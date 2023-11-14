#include <stdio.h>
#include <math.h>
#define N 4
int end = 0;
void print_buffer(char *t,int n){
    int i;
    printf("\n");
    for(i = 0;i<n;i++) printf("[%d]",t[i]);
}
void fill_buffer(char *t,int n,int a,int indx,int current){
    if(a>=pow(2,n)) return;
    int i=current,curr_indx = indx+1,tst=0;

    while (1)
    {
        if(curr_indx >= n || end) break;

        i+=pow(2,n-curr_indx-1);
        t[curr_indx] = 1;
 
        if(i>a){
            t[curr_indx] =0;
            fill_buffer(t,n,a,curr_indx,i-pow(2,n-curr_indx-1));
        }else if (i == a){
            end=1;
            return;
        } 
        curr_indx++;
    }
}
int main(){
    char buffer[N];
    int i,j,k,r;
    for(r=0;r<pow(2,N);r++){
        i=1;
        j=N-1;
        for(k=0;k<N-1;k++) buffer[k] = 0;
        buffer[N-1]=1;
        k=1;
        while(1){
            if(i>r){
                i/=2;
                buffer[j++]=0;
                buffer[j]=1;
                break;
            }else if (i == r){
                k=0;
                break;
            } 
            i*=2;
            buffer[j--]=0;
            buffer[j]=1;
        }
        if(k) fill_buffer(buffer,N,r,j,pow(2,N-j-1));
        print_buffer(buffer,N);
        end =0;
    }
    
    return 0;
}