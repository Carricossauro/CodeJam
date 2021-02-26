# This is CodeJam 2020 Nesting Depth
def solve(string):
    par = 0
    final = ""
    for item in string:
        p = int(item) - par
        if p > 0:
            final += "("*p + item
            par += p
        elif p < 0:
            final += ")"*(-p) + item
            par += p
        else:
            final += item
    return final + ")"*par

def main():
    T = int(input())
    for k in range(T):
        string = input()
        print("Case #" + str(k+1) + ": " + solve(string)) 
    return 0
    
main()
