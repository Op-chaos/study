import re

try:
    while 1:
        s = raw_input()

        a = re.findall(r'(.{3,}).*\1',s)