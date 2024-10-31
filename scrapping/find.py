import os, threading, requests, sqlite3
from bs4 import BeautifulSoup


with open("sitemap.xml", 'r') as f:
    content = f.readlines()

content = content[2].split("https")

l = []
searched = "://readi.fi/asset"
for url in content:
    if searched in url:
        l.append("https"+url)


l_title_desc = []
print("getting content")
for url in l:
    response = requests.get(url)
    soup = BeautifulSoup(response.content, "html.parser")

    # get title
    title = soup.title.string if soup.title else "No title found"
    
    # get description
    meta_description = soup.find("meta", attrs={"name": "description"})
    description_content = meta_description['content'] if meta_description else "No description found"

    l_title_desc.append([title, description_content])

print("Done")


print("Adding to DB")

DB_NAME = "data.db"
# Connect to the SQLite database (creates the file if it doesn't exist)
connection = sqlite3.connect(DB_NAME)

# Create a cursor object to execute SQL queries
cursor = connection.cursor()

# Create the table if it does not exist
cursor.execute('''
    CREATE TABLE IF NOT EXISTS scraped_data (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        title TEXT,
        description TEXT
    );
''')

for title, desc in l_title_desc:

    cursor.execute('''
        SELECT * FROM scraped_data WHERE title = ? AND description = ?;
    ''', (title, desc))


    result = cursor.fetchone()

    if result is None:
        print(title)
        cursor.execute('''
            INSERT INTO scraped_data (title, description) VALUES (?, ?);
        ''', (title, desc))

        connection.commit()


connection.close()

print("Done.")
