import os

file_name = input("Enter the filename you search:  ")
message = False

def search_file(path, name):
    global message
    for item in os.listdir(path):
        if item == name:
            print("\n-----------------------------------------\nFile finded:\n" + item + "\t\t" + path)
            message = True
        elif "." not in item:
            try:
                search_file(path + "\\" + item, name)
            except:
                pass

print("Searching...")
search_file("C:\\", file_name)
try:
    search_file("D:\\", file_name)
except:
    print("")

if not message:   
    print("File not finded!")
else:
    print("\n\n\nPress any key to exit...")
    input("")
