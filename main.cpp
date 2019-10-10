//filename: affine_gap.cpp
//use BLOSUM62 and definition of affine gap as a + b(L1-1)

#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

int pos(char aa)
{
    char *amino = (char*)"ARNDCQEGHILKMFPSTWYV-";
    for(int i=0;i<21;i++)
    {
        if(aa == amino[i]) return i;
    }
}

using namespace std;

int main()
{
    char *s = (char*)"MAGKAAEERGLPKGATPQDTSGLQDRLFSSESDNSLYFTYSGQPNTLEVRDLNYQVDLASQVPWFEQLAQFKMPWTSPSCQNSCELGIQNLSFKVRSGQMLAIIGSSGCGRASLLDVITGRGHGGKIKSGQIWINGQPSSPQLVRKCVAHVRQHNQLLPNLTVRETLAFIAQMRLPRTFSQAQRDKRVEDVIAELRLRQCADTRVGNMYVRGLSGGERRRVSIGVQLLWNPGILILDEPTSGLDSFTAHNLVKTLSRLAKGNRLVLISLHQPRSDIFRLFDLVLLMTSGTPIYLGAAQHMVQYFTAIGYPCPRYSNPADFYVDLTSIDRRSREQELATREKAQSLAALFLEKVRDLDDFLWKAETKDLDEDTCVESSVTPLDTNCLPSPTKMPGAVQQFTTLIRRQISNDFRDLPTLLIHGAEACLMSMTIGFLYFGHGSIQLSFMDTAALLFMIGALIPFNVILDVISKCYSERAMLYYELEDGLYTTGPYFFAKILGELPEHCAYIIIYGMPTYWLANLRPGLQPFLLHFLLVWLVVFCCRIMALAAAALLPTFHMASFFSNALYNSFYLAGGFMINLSSLWTVPAWISKVSFLRWCFEGLMKIQFSRRTYKMPLGNLTIAVSGDKILSVMELDSYPLYAIYLIVIGLSGGFMVLYYVSLRFIKQKPSQDW";//ABCG8
    char *t = (char*)"MGDLSSLTPGGSMGLQVNRGSQSSLEGAPATAPEPHSLGILHASYSVSHRVRPWWDITSCRQQWTRQILKDVSLYVESGQIMCILGSSGSGKTTLLDAMSGRLGRAGTFLGEVYVNGRALRREQFQDCFSYVLQSDTLLSSLTVRETLHYTALLAIRRGNPGSFQKKVEAVMAELSLSHVADRLIGNYSLGGISTGERRRVSIAAQLLQDPKVMLFDEPTTGLDCMTANQIVVLLVELARRNRIVVLTIHQPRSELFQLFDKIAILSFGELIFCGTPAEMLDFFNDCGYPCPEHSNPFDFYMDLTSVDTQSKEREIETSKRVQMIESAYKKSAICHKTLKNIERMKHLKTLPMVPFKTKDSPGVFSKLGVLLRRVTRNLVRNKLAVITRLLQNLIMGLFLLFFVLRVRSNVLKGAIQDRVGLLYQFVGATPYTGMLNAVNLFPVLRAVSDQESQDGLYQKWQMMLAYALHVLPFSVVATMIFSSVCYWTLGLHPEVARFGYFSAALLAPHLIGEFLTLVLLGIVQNPNIVNSVVALLSIAGVLVGSGFLRNIQEMPIPFKIISYFTFQKYCSEILVVNEFYGLNFTCGSSNVSVTTNPMCAFTQGIQFIEKTCPGATSRFTMNFLILYSFIPALVILGIVVFKIRDHLISR";//ABCG5
    //char *s = "MAGKAAC";
    //char *t = "AACRLLV";

    int BLOSUM62[21][21];
    ifstream f("B62.txt");//a file containing the BLOSUM62 matrix with row21 and colomn 21 filled with 11
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            {f>>BLOSUM62[i][j];}

    //checking if BLOSUM62 matrix stored correctly
	/*for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
            {cout << BLOSUM62[i][j] << ' ';}
        cout << endl;
    }*/

    int m = strlen(s)+1;
    int n = strlen(t)+1;

    int **A = new int *[m];//score matrix
    int **E = new int *[m];//A matrix tracking the length of gap extension

    for(int i=0;i<m;i++)
    {
        A[i] = new int[n];
        E[i] = new int[n];
    }

    for(int i=0;i<m;i++){A[i][0]=0; E[i][0]=0;}//initiate the first row and column with zeros
    for(int j=1;j<n;j++){A[0][j]=0; E[0][j]=0;}//initiate the first row and column with zeros

    int max_score = 0;
    int row_idx = 0;//row index for max_score
    int col_idx = 0;//column index for max_score

    int match = 0;//matching score from BLOSUM62
    int gap = 0;
    gap = BLOSUM62[20][20];//a gap penalty of 11
    int step_max = 0;//store the result from comparison

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {

            match = BLOSUM62[pos(s[i-1])][pos(t[j-1])];//match or mismatch
            step_max = max(max(A[i-1][j-1]+match,0),max(A[i-1][j]-gap-E[i-1][j],A[i][j-1]-gap-E[i][j-1]));//which score is the maximum
            A[i][j] = step_max;
            if(step_max == A[i-1][j-1]+match || step_max == 0)//by default: do match or mismatch first
            {
                E[i][j] = 0;//if match, no extension any more
            }
            else if(step_max == A[i-1][j]-gap-E[i-1][j])
            {
                E[i][j] = E[i-1][j]+1;//s1 extension
            }
            else
            {
                E[i][j] = E[i][j-1]+1;//s2 extension
            }

            if(A[i][j]>max_score)//tracking index
            {
                max_score = A[i][j];
                row_idx = i;
                col_idx = j;
            }
        }
    }

    //visulize score matrix(debug)
	/*for(int i=617;i<627;i++)
    {
        for(int j=589;j<599;j++)
            cout << A[i][j]<<'\t';
        cout << endl;
    }*/
    cout << endl;
    cout << max_score << endl;
    cout << row_idx << ' ' << col_idx << endl;

    if(!max_score) {cout << "No Match!" << endl; return 0;}

    stack<char> s_stack;
    stack<char> t_stack;
    m = row_idx;
    n = col_idx;
    while(A[m][n]||A[m+1][n]||A[m][n+1])//backtracking
    {
        if(A[m][n] == A[m-1][n] - gap - E[m-1][n])
        {
            s_stack.push(s[m-1]);
            t_stack.push('-');
            m--;
        }
        else if(A[m][n] == A[m][n-1] - gap - E[m][n-1])
        {
            t_stack.push(t[n-1]);
            s_stack.push('-');
            n--;
        }
        else
        {
            t_stack.push(t[n-1]);
            s_stack.push(s[m-1]);
            m--; n--;
        }
    }

    //cout << m << ' ' << n << endl;
    while(!s_stack.empty()){cout << s_stack.top(); s_stack.pop();}
    cout << endl;
    while(!t_stack.empty()){cout << t_stack.top(); t_stack.pop();}

    return 0;
}
