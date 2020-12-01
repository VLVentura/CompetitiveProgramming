import sys

from mainscript import Script

if __name__ == '__main__':
    args = sys.argv
    script = Script(args)
    script.run()
