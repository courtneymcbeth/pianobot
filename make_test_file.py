time = 0
key = 21

blackKeys = [22, 25, 27, 30, 32, 34, 37, 39, 42, 44, 46, 49,
             51, 54, 56, 58, 61, 63, 66, 68, 70, 73, 75, 78, 80, 82, 85, 87,
             90, 92, 94, 97, 99, 102, 104, 106]

with open("black_tester.txt", "w") as file:
    for i in range(len(blackKeys)):
        file.write(str(time) + "," + str(blackKeys[i]) + "\n")
        file.write(str(time + 500) + "," + str(blackKeys[i]) + "\n")
        key = key + 1
        time = time + 1000
    file.write("eof")
    file.close()
