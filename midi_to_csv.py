# python 36 virtual environment
import py_midicsv

# # Load the MIDI file and parse it into CSV format
csv_string = py_midicsv.midi_to_csv("the_entertainer.mid")

with open('the_entertainer.csv', 'w') as file:
    for line in csv_string:
        file.write(line)

print("success")
