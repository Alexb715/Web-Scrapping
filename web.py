from bs4 import BeautifulSoup
import requests
#creates map to store occurence of what number has been drawn
number_map = {i: 0 for i in range(1, 51)}
for i in range(2009,2025):
    #gets html from web sit that hass all the past winnings
    currentpage = "https://ca.lottonumbers.com/lotto-max/numbers/" + str(i)
    response = requests.get(currentpage)
    #parses
    soup = BeautifulSoup(response.content)
    #for all tags with the class ball ball "which is the area where the number is keept"
    for j in soup.find_all(class_='ball ball'):
        #add it in the map
        number_map[int(j.get_text())] += 1
        
# 1. Find numbers that have never been played (count is 0)
never_played = [num for num, count in number_map.items() if count == 0]

# 2. Find the best numbers to pick (sorted by highest occurrences)
sorted_numbers = sorted(number_map.items(), key=lambda x: x[1], reverse=True)

# Extract just the numbers in sorted order (for the best numbers to pick)
best_numbers = [num for num, count in sorted_numbers]

# Output results
print("Numbers that have never been played:", never_played)
print("Best numbers to pick (most frequently played):", best_numbers)