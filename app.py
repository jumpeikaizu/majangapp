from subprocess import Popen, PIPE
from flask import Flask, redirect, request, render_template

app = Flask(__name__)
p = Popen("./a.out", stdout=PIPE, stdin=PIPE)

@app.route('/')
def show():
    turn = p.stdout.readline()
    tehai = p.stdout.readline().split(' ')
    result = p.stdout.readline()
    del tehai[14]
    return render_template("show.html", turn=turn, tehai=tehai,result=result)

@app.route('/post',methods=['POST'])
def post():
    p.stdin.write(request.form['hai']+'\n')
    turn = p.stdout.readline()
    tehai = p.stdout.readline().split(' ')
    result = p.stdout.readline()
    del tehai[14]
    #if result == "end\n":
    #    return render_template("show.html" ,turn=turn, tehai=tehai)
    return render_template("show.html", turn=turn, tehai=tehai, result=result)
    #return request.form['hai']
    
@app.errorhandler(404)
def page_not_found(error):
    return 'Nothing here, sorry', 404

if __name__ == '__main__':
    app.run(debug=True)
