import subprocess

def run( problem, code):
    path1 = "../deer-executor" + " run "
    path2 = "../data/problems/" + problem + "/problem.json" + " "
    path3 = "../data/codes/" + problem + "/" + code + ".cpp"
    path = path1 + path2 + path3
    res = subprocess.run(path, shell=True)
    print(res)

run('APlusB', 'ac')