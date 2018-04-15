#include<stdio.h>
void main(int argn,char*argv[])
{
  FILE *fp1;
  FILE *fp2;
  char c;
  clrscr();
  if(argn==3){
    fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"w");
    if((fp1!=-1) || (fp2 != -1)){
      while((c=getc(fp1))!=EOF)
       {
         putc(c,fp2);
       }
      fclose(fp1);
      fclose(fp2);
    }else{
      printf("file operation falure");
    }
  }
  else{
    printf("insuffient arguements");
  }
  getch();
}
