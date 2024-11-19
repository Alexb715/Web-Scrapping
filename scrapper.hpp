#include "iostream"
#include "string"
#include "curl/curl.h"
#include "Parse.hpp"
#include "string.h"
#include <curl/easy.h>
#include <curl/urlapi.h>
#include <string>
using namespace std;
typedef size_t( * curl_write)(char * , size_t, size_t, std::string * );

class Scrap{
    
    private:
    CURLcode res_code = CURLE_FAILED_INIT;
    CURL *curl = curl_easy_init();
    string Curlresult;
    string url = "https://www.merriam-webster.com/dictionary/esoteric";
    string res;
    string name = "lead";
    string atribute = "class";
   
    void Curl(){
        curl_global_init(CURL_GLOBAL_ALL);
    if (curl) {
        curl_easy_setopt(curl,
      CURLOPT_WRITEFUNCTION,
      static_cast < curl_write > ([](char * contents, size_t size,
        size_t nmemb, std::string * data) -> size_t {
        size_t new_size = size * nmemb;
        if (data == NULL) {
          return 0;
        }
        data -> append(contents, new_size);
        return new_size;
      }));
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, & Curlresult);
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_USERAGENT, "simple scraper");

            res_code = curl_easy_perform(curl);

            if (res_code != CURLE_OK) {
                cout << curl_easy_strerror(res_code);
        }

        curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

    }
   
    public:
    void init(){
        Curl();
        cout << Curlresult;
    }
};