#include <string>
#include<vector>
using namespace std;
struct node
{
    string tag;
    string id;
    string className;
    node* parent;
    vector<node*> child;
};

class parse{
    private:
    node* root;
    string html;









    public:
    parse(string &data){
        html = data;
    }

};