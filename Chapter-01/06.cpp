#include <bits/stdc++.h>

using namespace std;

int exec (int command,  vector<int> &regs, vector<int> &mem, int d, int n)
{
    //cout << command << " " << d << " " << n << endl;
    switch(command)
    {
    case 2:
        regs[d] = n % 1000;
        return 1;
    case 3:
        regs[d] = (regs[d] + n) % 1000;
        return 1;
    case 4:
        regs[d] = (regs[d] * n) % 1000;
        return 1;
    case 5:
        regs[d] = regs[n] % 1000;
        return 1;
    case 6:
        regs[d] = (regs[d] + regs[n]) % 1000;
        return 1;
    case 7:
        regs[d] = (regs[d] * regs[n]) % 1000;
        return 1;
    case 8:
        regs[d] = mem[regs[n]] % 1000;
        return 1;
    case 9:
        mem[regs[n]] = regs[d] % 1000;
        return 1;
    }

    return 0;
}

int main()
{
    //ofstream txtOut;
    //txtOut.open("newFile.txt");
    int t;
    scanf("%d ", &t);
    vector<int> reg(10);
    vector<int> mem(1000);
    vector<int> answers;
    char cmd[5];
    int pc = 0 , ans = 0;
    while(t--)
    {
        reg.clear();
        reg.resize(10);
        mem.clear();
        mem.resize(1000);
        ans = pc = 0;
        while(gets(cmd))
        {
            if(cmd[0] == '\0')
                break;
            mem[pc++] = atoi(cmd);
        }
        pc = 0;
        while(true)
        {   ans++;
            int c = (mem[pc] / 100), d = (mem[pc] / 10) %10 , n = mem[pc] % 10;
            if (c == 1) break;
            else if (c == 0 && reg[n] != 0) {pc = reg[d]; continue;}
            else exec(c , reg , mem , d , n);
            pc++;
        }
        answers.push_back(ans);
    }

    for (int i = 0 ; i < answers.size() ; i++){
        if (i == answers.size() - 1){
            printf("%d\n" , answers[i]);
            //txtOut << answers[i] << '\n';
        }else {
            printf("%d\n\n" , answers[i]);
            //txtOut << answers[i] << "\n\n";
        }
    }

    return 0;
}
