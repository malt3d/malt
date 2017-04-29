import subprocess
import sys
import re
import shutil

def find_objdump():
    def try_ex(path):
        proc = subprocess.Popen([path, "--v"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout,stderr = proc.communicate()
        if str(stdout).find("GNU") > 0:
            return True
        return False

    objd = shutil.which("objdump")
    if try_ex(objd):
        return objd

    objd = shutil.which("gobjdump")
    if try_ex(objd):
        return objd

    return None

def parse_line(line):
    pat = r'malt::impl::msg_delivery<(.*?) \((.*?)\)>'
    if re.search(pat, line):
        match = re.search(pat, line)
        return match.group(1), match.group(2).split(', ')

def run_objdump(lib_file):
    proc = subprocess.Popen([find_objdump(), "-TC", lib_file], stdout=subprocess.PIPE, stderr=subprocess.PIPE, bufsize=1, universal_newlines=True)
    lines = []
    for line in iter(proc.stdout.readline, ''):
        if (line != '\n'):
            lines.append(parse_line(line.replace('\n', '')))
    return list(filter(lambda x : not x is None, lines))

for (msg, args) in (run_objdump(sys.argv[1])):
    t = '{}({})'.format(msg, ", ".join(args))
    print (t)
