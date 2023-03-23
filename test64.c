#include<stdio.h>
//question 2
 void func(int m ,int p, int c)
 {
      int total1=0;
       int temp2;      
         int temp1=(m/p);
         int temp3=temp1;
       

      while((temp3*c)>=p)
       {
       
          temp2=((c*temp3)/p);
             
            temp3=((temp2*c)/p);
            printf("%d\n",temp2);
            printf("%d\n",temp3);
            total1=temp2+temp3+total1;
            
           }

     int  totalc=temp1+total1;
    printf("total=%d\n",totalc);

}
    
 int main()
  {
    int p,m,c;
     int totalc;
    
     printf("enter the total amount of money");
     scanf("%d",&m);
     printf("enter the price of chocolate");
     scanf("%d",&p);
     printf("enter the cashbck");
     scanf("%d",&c);
     func(m,p,c);
        
    }
    
