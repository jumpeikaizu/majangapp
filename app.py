from subprocess import Popen, PIPE
from flask import Flask, redirect, request, render_template

app = Flask(__name__)
p = Popen("./a.out", stdout=PIPE, stdin=PIPE)

@app.route('/')
def show():
    #refresh = request.args.get("refresh") or "3"
    tehai = p.stdout.readline().split(' ')
    del tehai[14]
    return render_template("show.html", tehai=tehai)

@app.route('/post',methods=['POST'])
def post():
    #refresh = request.args.get("refresh") or "3"
    p.stdin.write(request.form['hai']+'\n')
    tehai = p.stdout.readline().split(' ')
    del tehai[14]
    return render_template("show.html",tehai=tehai)
    #return request.form['hai']
    
@app.errorhandler(404)
def page_not_found(error):
    return 'Nothing here, sorry', 404

if __name__ == '__main__':
    app.run(debug=True)
