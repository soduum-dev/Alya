import subprocess as sub
import pathlib as pt

class nah(Exception):
    def __init__(self, msg):
        self.msg = msg

    def about(self):
        print(self.msg)

try:
    if (pt.Path.home() / "alya").exists():
        raise nah("was installed") 
    print("creating dir tree")
    sub.run("mkdir -p ~/alya/bashrcs_history", shell=True)
    sub.run("mkdir -p ~/alya/licences", shell=True)
    sub.run("git init ~/alya/bashrcs_history", shell=True)
except sub.CalledProcessError as e:
    print(e.returncode," ~bug")
    raise
except nah as e:
    e.about()
    exit(1)

print("installed")
