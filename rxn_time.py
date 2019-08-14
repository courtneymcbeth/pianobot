filename = "the_entertainer.txt"
addOn = 50
delay = 0

newName = filename.split(".")[0] + "_rxn.txt"

lastTime = 0
with open(filename, "r") as origFile:
    with open(newName, "w") as newFile:
        line = origFile.readline()
        while not "eof" in line:
            lst = line.split(",")
            if "off" in lst[2]:
                if not int(lst[0]) == lastTime:
                    delay = delay + addOn
                    lastTime = int(lst[0])
                newFile.write(str(int(lst[0]) + delay) +
                              "," + lst[1] + "," + lst[2])
            else:
                newFile.write(str(int(lst[0]) + delay) +
                              "," + lst[1] + "," + lst[2])
            line = origFile.readline()
        newFile.write("eof\n")
