#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct shopping 
{
    char brand_name[25];
    int pro_id_no;
    char pro_name[25];
    int price;
    char color[25];
    int stock;
    char dealer[25];
    int offer;
    int sold;
};
struct category
{
    struct shopping mobile;
    struct shopping tv;
    struct shopping laptops;
    struct shopping fashion;
    struct shopping furniture;
}s[5];


struct user_history
 {
        char product_purchased[15];
        int amount;
        char product_review[20];
        int rating;
 }user_history[31];

struct customer
{
    int ID;
    char password[15];
    char name[20];
    char address[100];
    struct user_history user_his[10];
    int date;
    
}user[10];

    

int validate_user(struct customer user[],int id,char pass[]);
int validate_user(struct customer user[],int id,char pass[])
{
    int i,valid=-1;
    for(i=0;i<10;i++)
    {
        if(user[i].ID==id && strcmp(user[i].password,pass)==0)
        {
            valid=i;
        }
    }
    return valid;

}
void validation();
void validation()

{
    struct customer user[10];
    struct category s[5];
    int id,valid=-1;
    char pass_word[25];
   printf("please enter your Id and password \n");
   scanf("%d",&id);
   scanf("%s",pass_word);
   valid=validate_user(user,id,pass_word);
   if (valid!=-1)
   {
       printf("you are a valid user\n");
       add_to_cart(s,valid);
   }
   else
   {
       printf("please sign up you are new user\n");
       sign_in(user);
   }
   
}
int empty(struct customer user[]);
int empty(struct customer user[])
{
    int i,found=0,ratval=-1;
    for(i=0;i<10&&found==0;i++)
    {
        if(user[i].ID==NULL)
        {
            ratval=i;
            found=1;
        }
    }
    return ratval;
}

void sign_in(struct customer user[]);
void sign_in(struct customer user[])
{
    struct category s[5];
    int i;
    i=empty(user);
    printf("your id is %d\n",i);
    printf("please make your password\n");
    scanf("%s",user[i].password);
    printf("please enter your name\n");
    scanf("%s",user[i].name);
    printf("please enter your address\n");
    scanf("%s",user[i].address);
    add_to_cart(s,i);
}




void add_to_cart(struct category s[],int n);
void add_to_cart(struct category s[],int n)
{
   char pro_name[25];
    printf("enter product name to purcahse\n");
    scanf("%s",pro_name);
    int amount;
    printf("enter number of product you want\n");
    scanf("%d",&amount);
    int i;
    for(i=0;i<5;i++)
    {
        if(strcmp(s[i].mobile.pro_name,pro_name)==0)
        {
            if(s[i].mobile.stock>amount)
            {
                s[i].mobile.stock-=amount;
                s[i].mobile.sold+=amount;
                
                printf("%s product has been purchased and its price is %d\n",s[i].mobile.pro_name,s[i].mobile.price);
            }
        }
        else if(strcmp(s[i].tv.pro_name,pro_name)==0)
        {
            if (s[i].tv.stock>amount)
            {
                s[i].tv.stock-=amount;
                s[i].tv.sold+=amount;
                printf("%s has been purchased and its price is %d\n",s[i].tv.pro_name,s[i].tv.price);
            }
            
        }
        else if(strcmp(s[i].laptops.pro_name,pro_name)==0)
        {
            if (s[i].laptops.stock>amount)
            {
                s[i].laptops.stock-=amount;
                s[i].laptops.sold+=amount;
                printf("%s has been purchased and its price is %d\n",s[i].laptops.pro_name,s[i].laptops.price);
            }
            
        }
        else if(strcmp(s[i].fashion.pro_name,pro_name)==0)
        {
            if (s[i].fashion.stock>amount)
            {
                s[i].fashion.stock-=amount;
                s[i].fashion.sold+=amount;
                printf("%s has been purchased and its price is %d\n",s[i].fashion.pro_name,s[i].fashion.price);
            }
            
        }
        else if(strcmp(s[i].furniture.pro_name,pro_name)==0)
        {
            if (s[i].furniture.stock>amount)
            {
                s[i].furniture.stock-=amount;
                s[i].furniture.sold+=amount;
                printf("%s has been purchased and its price is %d\n",s[i].furniture.pro_name,s[i].furniture.price);
            }
            
        }
        
        
    }
    int date;
    printf("please enter todays date\n");
    scanf("%d",&date);
    strcpy(user[i].user_his[date].product_purchased,pro_name);
    user[i].user_his[date].amount=amount;
    printf("please give review for this product\n");
    scanf("%s",user[i].user_his[date].product_review);
    printf("and also rate ur purchase on 1 to 5 scale\n");
    scanf("%d",&user[i].user_his[date].rating);
    printf("thank you for purchasing %s and come again\n",pro_name);
    recomend(pro_name,n);
}

void recomend(char pro[],int n);
void recomend(char pro[],int n)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        if(strcmp(s[i].mobile.pro_name,pro)==0)
        {
           j=0;
           while (j<5)
           {
               printf("%s are similar prodcut\n",s[j].mobile.pro_name);
           }
            
        }
        else if(strcmp(s[i].tv.pro_name,pro)==0)
        {
             j=0;
           while (j<5)
           {
               printf("%s are similar prodcut\n",s[j].tv.pro_name);
           }
        }
        else if(strcmp(s[i].laptops.pro_name,pro)==0)
        {
             j=0;
           while (j<5)
           {
               printf("%s are similar prodcut\n",s[j].laptops.pro_name);
           }
        }
        else if(strcmp(s[i].fashion.pro_name,pro)==0)
        {
             j=0;
           while (j<5)
           {
               printf("%s are similar prodcut\n",s[j].fashion.pro_name);
           }
        }
        else if(strcmp(s[i].furniture.pro_name,pro)==0)
        {
             j=0;
           while (j<5)
           {
               printf("%s are similar prodcut\n",s[j].furniture.pro_name);
           }
        }

    }
    int cart_category;
    printf("would you like to buy recommended product press 1 \nor any key to quit\n");
    scanf("%d",&cart_category);
    if(cart_category==1)
    {
        add_to_cart(s,n);
    }

}

void best_seller_criteria(struct category s[],int n);
void best_seller_criteria(struct category s[],int n)
{

    int i;
    for ( i = 0; i < 5; i++)
    {
        if(n==1)
        {
        
            if(s[i].mobile.price<=20000 && s[i].mobile.sold>=0)
            {
                printf("%s mobile and its price is %d\n",s[i].mobile.pro_name,s[i].mobile.price);
            }
        }

        else if(n==2)
        {
            
            if(s[i].tv.price<=40000 &&s[i].tv.sold>0)
            {
                printf("%s tv by %s and its price is %d\n",s[i].tv.pro_name,s[i].tv.brand_name,s[i].tv.price);
            }
        }

        else if(n==3)
        {
        
            if (s[i].laptops.price<=80000 && s[i].laptops.sold>0)
            {
                printf("%s laptop and its price is %d\n",s[i].laptops.pro_name,s[i].laptops.price);
            }
            
        }
        else if(n==4)
        {
        
            if(s[i].fashion.price<4000 && s[i].fashion.sold>2)
            {
                printf("%s product and its price is %d\n",s[i].fashion.pro_name,s[i].fashion.price);
            }
        }

        else
        {
            
            if(s[i].furniture.price<20000 && s[i].furniture.sold>0)
            {
                printf("%s product and its price is %d\n",s[i].furniture.pro_name,s[i].furniture.price);
            }
        }
        validation();
        
    }
    
}




void main()
{
    struct category s[5];
    struct customer user[10];
    
    user[0].ID=0;
    strcpy(user[0].name,"khan");
    strcpy(user[0].password,"pass");
    strcpy(user[0].address,"nagpur");
    
    


    strcpy(s[0].mobile.brand_name,"redmi");
    s[0].mobile.pro_id_no=00001;
    strcpy(s[0].mobile.pro_name,"note_5_pro");
    s[0].mobile.price=19999;
    strcpy(s[0].mobile.color,"black");
    s[0].mobile.stock=10;
    strcpy(s[0].mobile.dealer,"Silver_sy");
    s[0].mobile.offer=100;
    s[0].mobile.sold=0;

    strcpy(s[1].mobile.brand_name,"samsung");
    s[1].mobile.pro_id_no=00002;
    strcpy(s[1].mobile.pro_name,"s9+");
    s[1].mobile.price=69999;
    strcpy(s[1].mobile.color,"black");
    s[1].mobile.stock=10;
    strcpy(s[1].mobile.dealer,"Silver_sy");
    s[1].mobile.offer=1000;
    s[1].mobile.sold=0;

    strcpy(s[2].mobile.brand_name,"nokia");
    s[0].mobile.pro_id_no=00003;
    strcpy(s[2].mobile.pro_name,"lumia");
    s[2].mobile.price=34999;
    strcpy(s[2].mobile.color,"yellow");
    s[2].mobile.stock=10;
    strcpy(s[2].mobile.dealer,"Silver_sy");
    s[2].mobile.offer=300;
    s[2].mobile.sold=0;

    strcpy(s[3].mobile.brand_name,"asus");
    s[3].mobile.pro_id_no=00004;
    strcpy(s[3].mobile.pro_name,"rog");
    s[3].mobile.price=79999;
    strcpy(s[3].mobile.color,"red");
    s[3].mobile.stock=10;
    strcpy(s[3].mobile.dealer,"Silver_sy");
    s[3].mobile.offer=0;
    s[3].mobile.sold=0;

    strcpy(s[4].mobile.brand_name,"oneplus");
    s[4].mobile.pro_id_no=00005;
    strcpy(s[4].mobile.pro_name,"note7pro");
    s[4].mobile.price=49999;
    strcpy(s[4].mobile.color,"black");
    s[4].mobile.stock=10;
    strcpy(s[4].mobile.dealer,"Silver_sy");
    s[4].mobile.offer=0;
    s[4].mobile.sold=0;

    strcpy(s[0].tv.brand_name,"sony");
    s[0].tv.pro_id_no=00006;
    strcpy(s[0].tv.pro_name,"bravia");
    s[0].tv.price=32000;
    strcpy(s[0].tv.color,"black");
    s[0].tv.stock=6;
    strcpy(s[0].tv.dealer,"Sony_pvt.lt");
    s[0].tv.offer=0;
    s[0].tv.sold=0;

    strcpy(s[1].tv.brand_name,"oneplus");
    s[1].tv.pro_id_no=00007;
    strcpy(s[1].tv.pro_name,"Q1_series");
    s[1].tv.price=65000;
    strcpy(s[1].tv.color,"black");
    s[1].tv.stock=5;
    strcpy(s[1].tv.dealer,"winkle");
    s[1].tv.offer=0;
    s[1].tv.sold=0;

    strcpy(s[2].tv.brand_name,"samsung");
    s[2].tv.pro_id_no=00011;
    strcpy(s[2].tv.pro_name,"LED_smart");
    s[2].tv.price=20000;
    strcpy(s[2].tv.color,"grey");
    s[2].tv.stock=6;
    strcpy(s[2].tv.dealer,"Samsung_pvt.lt");
    s[2].tv.offer=100;
    s[2].tv.sold=0;

    strcpy(s[3].tv.brand_name,"LG");
    s[3].tv.pro_id_no=00012;
    strcpy(s[3].tv.pro_name,"LED_tv");
    s[3].tv.price=16000;
    strcpy(s[3].tv.color,"black");
    s[3].tv.stock=6;
    strcpy(s[3].tv.dealer,"Lg_pvt.lt");
    s[3].tv.offer=200;
    s[3].tv.sold=0;

    strcpy(s[4].tv.brand_name,"Xiaomi");
    s[4].tv.pro_id_no=00013;
    strcpy(s[4].tv.pro_name,"mi_LED_smart");
    s[4].tv.price=24999;
    strcpy(s[4].tv.color,"black");
    s[4].tv.stock=6;
    strcpy(s[4].tv.dealer,"Silver_sys");
    s[4].tv.offer=0;
    s[4].tv.sold=0;

    strcpy(s[0].laptops.brand_name,"acer");
    s[0].laptops.pro_id_no=00014;
    strcpy(s[0].laptops.pro_name,"Predator");
    s[0].laptops.price=80000;
    strcpy(s[0].laptops.color,"black");
    s[0].laptops.stock=10;
    strcpy(s[0].laptops.dealer,"winkel");
    s[0].laptops.offer=1000;
    s[0].laptops.sold=0;

    strcpy(s[1].laptops.brand_name,"asus");
    s[1].laptops.pro_id_no=00015;
    strcpy(s[1].laptops.pro_name,"rog");
    s[1].laptops.price=80000;
    strcpy(s[1].laptops.color,"violet");
    s[1].laptops.stock=10;
    strcpy(s[1].laptops.dealer,"winkel");
    s[1].laptops.offer=1000;
    s[1].laptops.sold=0;

    strcpy(s[2].laptops.brand_name,"dell");
    s[2].laptops.pro_id_no=00016;
    strcpy(s[2].laptops.pro_name,"bullet");
    s[2].laptops.price=79000;
    strcpy(s[2].laptops.color,"blue");
    s[2].laptops.stock=10;
    strcpy(s[2].laptops.dealer,"winkel");
    s[2].laptops.offer=0;
    s[2].laptops.sold=0;

    strcpy(s[3].laptops.brand_name,"HP");
    s[3].laptops.pro_id_no=00017;
    strcpy(s[3].laptops.pro_name,"Pavallion");
    s[3].laptops.price=75000;
    strcpy(s[3].laptops.color,"grey");
    s[3].laptops.stock=10;
    strcpy(s[3].laptops.dealer,"HP_world");
    s[3].laptops.offer=0;
    s[3].laptops.sold=0;

    strcpy(s[4].laptops.brand_name,"lenovo");
    s[4].laptops.pro_id_no=00021;
    strcpy(s[4].laptops.pro_name,"idealpad");
    s[4].laptops.price=73000;
    strcpy(s[4].laptops.color,"grey");
    s[4].laptops.stock=10;
    strcpy(s[4].laptops.dealer,"silver_sys");
    s[4].laptops.offer=500;
    s[4].laptops.sold=0;

    strcpy(s[0].fashion.brand_name,"levi");
    s[0].fashion.pro_id_no=00022;
    strcpy(s[0].fashion.pro_name,"jeans");
    s[0].fashion.price=3200;
    strcpy(s[0].fashion.color,"blue");
    s[0].fashion.stock=15;
    strcpy(s[0].fashion.dealer,"levi_pvt.lt");
    s[0].fashion.offer=1600;
    s[0].fashion.sold=0;

    strcpy(s[1].fashion.brand_name,"levi");
    s[1].fashion.pro_id_no=00023;
    strcpy(s[1].fashion.pro_name,"shirt");
    s[1].fashion.price=1500;
    strcpy(s[1].fashion.color,"checked_blue");
    s[1].fashion.stock=15;
    strcpy(s[1].fashion.dealer,"levi_pvt.lt");
    s[1].fashion.offer=750;
    s[1].fashion.sold=0;

    strcpy(s[2].fashion.brand_name,"mufti");
    s[2].fashion.pro_id_no=00024;
    strcpy(s[2].fashion.pro_name,"jeans");
    s[2].fashion.price=3200;
    strcpy(s[2].fashion.color,"blue");
    s[2].fashion.stock=15;
    strcpy(s[2].fashion.dealer,"mufti_pvt.lt");
    s[2].fashion.offer=1600;
    s[2].fashion.sold=0;

    strcpy(s[3].fashion.brand_name,"mufti");
    s[3].fashion.pro_id_no=00025;
    strcpy(s[3].fashion.pro_name,"shirt");
    s[3].fashion.price=1500;
    strcpy(s[3].fashion.color,"plain_blue");
    s[3].fashion.stock=15;
    strcpy(s[3].fashion.dealer,"mufti_pvt.lt");
    s[3].fashion.offer=750;
    s[3].fashion.sold=0;

    strcpy(s[4].fashion.brand_name,"spkar");
    s[4].fashion.pro_id_no=00026;
    strcpy(s[4].fashion.pro_name,"jeans");
    s[4].fashion.price=3200;
    strcpy(s[4].fashion.color,"blue");
    s[4].fashion.stock=15;
    strcpy(s[4].fashion.dealer,"spkar_pvt.lt");
    s[4].fashion.offer=0;
    s[4].fashion.sold=0;

    strcpy(s[0].furniture.brand_name,"spacewood");
    s[0].furniture.pro_id_no=00027;
    strcpy(s[0].furniture.pro_name,"bed");
    s[0].furniture.price=18999;
    strcpy(s[0].furniture.color,"balck");
    s[0].furniture.stock=9;
    strcpy(s[0].furniture.dealer,"Bharat");
    s[0].furniture.offer=500;
    s[0].furniture.sold=0;

    strcpy(s[1].furniture.brand_name,"spacewood");
    s[1].furniture.pro_id_no=00031;
    strcpy(s[1].furniture.pro_name,"wardrobe");
    s[1].furniture.price=19999;
    strcpy(s[1].furniture.color,"brown");
    s[1].furniture.stock=8;
    strcpy(s[1].furniture.dealer,"Bharat");
    s[1].furniture.offer=0;
    s[1].furniture.offer=0;

    strcpy(s[2].furniture.brand_name,"novelty");
    s[2].furniture.pro_id_no=00032;
    strcpy(s[2].furniture.pro_name,"wardrobe");
    s[2].furniture.price=28999;
    strcpy(s[2].furniture.color,"brown");
    s[2].furniture.stock=11;
    strcpy(s[2].furniture.dealer,"Bharat");
    s[2].furniture.offer=700;
    s[2].furniture.sold=0;

    strcpy(s[3].furniture.brand_name,"novelty");
    s[3].furniture.pro_id_no=00033;
    strcpy(s[3].furniture.pro_name,"TV_stand");
    s[3].furniture.price=8999;
    strcpy(s[3].furniture.color,"black");
    s[3].furniture.stock=7;
    strcpy(s[3].furniture.dealer,"Bharat");
    s[3].furniture.offer=150;
    s[3].furniture.sold=0;

    strcpy(s[4].furniture.brand_name,"spacewood");
    s[4].furniture.pro_id_no=00034;
    strcpy(s[4].furniture.pro_name,"shoe_kepper");
    s[4].furniture.price=7999;
    strcpy(s[4].furniture.color,"brown");
    s[4].furniture.stock=4;
    strcpy(s[4].furniture.dealer,"Bharat");
    s[4].furniture.offer=500;
    s[4].furniture.sold=0;



     int search,i;
    char proname[25],brandname[25];
    int cart_category;
    printf("enter given no to search the product\n");
    printf("1 search by category\n2 search by product name\n3 search by brand name\n4 to see most frequently buyied product\n5 to see available offers on products\n");
    scanf("%d",&search);

    if(search==1)
    {
        
        printf("display products by given categories\n");
        printf("1 to display moblies\n2 to display tv\n3 to display laptops\n4 to display fashion\n5 to display furniture\n");
        int search1;
        
        scanf("%d",&search1);
        if(search1==1)
        {

            for(i=0;i<5;i++)
            {
                printf("%s powered by %s and price is %d\n",s[i].mobile.pro_name,s[i].mobile.brand_name,s[i].mobile.price);
            }
            
        }
        else if(search1==2)
        {
            for ( i = 0; i < 5; i++)
            {
                printf("%s powered by %s and its price is %d\n",s[i].tv.pro_name,s[i].tv.brand_name,s[i].tv.price);

            }
            
        }
        else if(search1==3)
        {
            for(i=0;i<5;i++)
            {
                printf("%s powered by %s and its price is %d\n",s[i].laptops.pro_name,s[i].laptops.brand_name,s[i].laptops.price);
            }
        }
        else if(search1==4)
        {
            for(i=0;i<5;i++)
            {
                printf("%s powered by %s and its price is %d\n",s[i].fashion.pro_name,s[i].fashion.brand_name,s[i].fashion.price);

            }
        }
        else
        {
            for ( i = 0; i < 5; i++)
            {
                printf("%s made by %s and its price is %d\n",s[i].furniture.pro_name,s[i].furniture.brand_name,s[i].furniture.price);
            }
            
        }
        
        printf("enter\n1 to buy product\n2 to quit\n");
        scanf("%d",&cart_category);
        if(cart_category==1){
            validation();
        }
        
        
        
    }
    else if(search==2)
    {
        printf("enter product name:\n");
        scanf("%s",proname);
        for ( i = 0; i < 5; i++)
        {
            if(strcmp(s[i].mobile.pro_name,proname)==0)
            {
                printf("%s is powered by %s and its price is %d\n",s[i].mobile.pro_name,s[i].mobile.brand_name,s[i].mobile.price);

            }
            else if(strcmp(s[i].tv.pro_name,proname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].tv.pro_name,s[i].tv.brand_name,s[i].tv.price);

            }
            else if(strcmp(s[i].laptops.pro_name,proname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].laptops.pro_name,s[i].laptops.brand_name,s[i].laptops.price);
            }
            else if (strcmp(s[i].fashion.pro_name,proname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].fashion.pro_name,s[i].fashion.brand_name,s[i].fashion.price);
            }
            else if(strcmp(s[i].furniture.pro_name,proname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].furniture.pro_name,s[i].furniture.brand_name,s[i].furniture.price);
            }
            
            
        }
        printf("enter\n1 to buy product\n2 to quit\n");
        scanf("%d",&cart_category);
        if(cart_category==1){
            validation();
        }
            
    }
        
    
    else if(search==3)
    {
        printf("enter brand name\n");
        gets(brandname);
        for ( i = 0; i < 5; i++)
        {
            if(strcmp(s[i].mobile.brand_name,brandname)==0)
            {
                printf("%s is powered by %s and its price is %d\n",s[i].mobile.pro_name,s[i].mobile.brand_name,s[i].mobile.price);

            }
            else if(strcmp(s[i].tv.brand_name,brandname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].tv.pro_name,s[i].tv.brand_name,s[i].tv.price);

            }
            else if(strcmp(s[i].laptops.brand_name,brandname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].laptops.pro_name,s[i].laptops.brand_name,s[i].laptops.price);
            }
            else if (strcmp(s[i].fashion.brand_name,brandname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].fashion.pro_name,s[i].fashion.brand_name,s[i].fashion.price);
            }
            else if(strcmp(s[i].furniture.brand_name,brandname)==0)
            {
                printf("%s powered by %s and its price is %d\n",s[i].furniture.pro_name,s[i].furniture.brand_name,s[i].furniture.price);
            }
        }
        printf("enter\n1 to buy product\n2 to quit\n");
        scanf("%d",&cart_category);
        if(cart_category==1){
            validation();
        }
        
    }

    else if(search==4)
    {
        printf("enter the product no to see their best seller criteria\n");
        printf("1 to see mobile\n2 to see tv\n3 to see laptops\n4 to see fashion\n5 to see funiture\n");
        int best_seller;
        scanf("%d",&best_seller);
        best_seller_criteria(s,best_seller);
    }
    else if(search==5)
    {
        for(i=0;i<5;i++)
        {
            if(s[i].mobile.offer>0)
            {
                printf("%s powered by %s and product have %d rupee off\n",s[i].mobile.pro_name,s[i].mobile.brand_name,s[i].mobile.offer);
            }

            if(s[i].tv.offer>0)
            {
                printf("%s powered by %s and product have %d rupee off\n",s[i].tv.pro_name,s[i].tv.brand_name,s[i].tv.offer);
            }

            if(s[i].laptops.offer>0)
            {
                printf("%s powered by %s and product have %d rupee off\n",s[i].laptops.pro_name,s[i].laptops.brand_name,s[i].laptops.offer);
            }

            if(s[i].fashion.offer>0)
            {
                printf("%s powered by %s and product have %d rupee off\n",s[i].fashion.pro_name,s[i].fashion.brand_name,s[i].fashion.offer);
            }

            if(s[i].furniture.offer>0)
            {
                printf("%s powered by %s and product have %d rupee off\n",s[i].furniture.pro_name,s[i].furniture.brand_name,s[i].furniture.offer);
            }
        }

        printf("enter\n1 to buy product\n2 to quit\n");
        scanf("%d",&cart_category);
        if(cart_category==1){
            validation();
        }
        
    }
}
