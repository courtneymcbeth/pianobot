from command import Command

fileName = "the_entertainer.csv"

cmds = []

with open(fileName, "r") as file:
    eof = False
    while not eof:
        line = file.readline()
        lst = line.split(",")
        if "Note_on_c" in lst[2]:
            cmds.append(Command(int(lst[1]), int(
                lst[4]), not int(lst[5]) == 0))
        if "End_of_file" in lst[2]:
            eof = True

cmds.sort(key=lambda c: c.time)

f = fileName.split(".")[0] + ".txt"

with open(f, "w") as file:
    for c in cmds:
        if c.cmd:
            file.write(str(c.time) + "," + str(c.key) + "," + "on\n")
        else:
            file.write(str(c.time) + "," + str(c.key) + "," + "off\n")
    file.write("eof")
