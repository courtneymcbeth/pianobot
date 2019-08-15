import py_midicsv
from command import Command

filename = "Flight_of_the_Bumblebee.mid"  # MIDI file for song to play

# Load the MIDI file and parse it into CSV format
csv_string = py_midicsv.midi_to_csv(filename)

# file names
baseName = filename.lower().split(".")[0]
csvName = baseName + ".csv"
txtName = baseName + ".txt"

# write csv file
with open(csvName, 'w') as file:
    for line in csv_string:
        file.write(line)

# read commands from the csv file
cmds = []
with open(csvName, "r") as file:
    eof = False
    while not eof:
        line = file.readline()
        lst = line.split(",")
        if "Note_on_c" in lst[2]:
            cmds.append(Command(int(lst[1]), int(
                lst[4]), not int(lst[5]) == 0))
        if "End_of_file" in lst[2]:
            eof = True

# sort commands by time (earliest first)
cmds.sort(key=lambda c: c.time)

# write commands to a txt file
with open(txtName, "w") as file:
    for c in cmds:
        if c.cmd:
            file.write(str(c.time) + "," + str(c.key) + "," + "on\n")
        else:
            file.write(str(c.time) + "," + str(c.key) + "," + "off\n")
    file.write("eof")

print("success")
