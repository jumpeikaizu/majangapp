import subprocess
import commands
if __name__ == "__main__":
    #data = subprocess.check_output(["./a.out"])
    #data = commands.getoutput("./a.out")
    p = subprocess.Popen("./a.out",stdout=subprocess.PIPE,stdin=subprocess.PIPE)
    print p.stdout.readline().split(' ')
    input1 = raw_input().strip()
    p.stdin.write(input1+"\n")
    #p.communicate("com")
    print p.stdout.readline()
