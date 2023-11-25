#include <stdio.h>
#include <string.h>

struct cart
{
    char product[20];
    int price;
    int gst;
    int qty;
};

typedef struct cart CART;

int main()
{
    int n = 4, r, g, q;
    char pro[20];

    CART prod[4];

    printf("Enter products:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d product:\n", i + 1);
        scanf("%s%d%d%d", &pro, &r, &g, &q);

        strcpy(prod[i].product, pro);
        prod[i].price = r;
        prod[i].gst = g;
        prod[i].qty = q;
    }

    // strcpy(prod[1].product ,"Leather Wallet");
    // prod[1].price = 1100;
    // prod[1].gst = 18;
    // prod[1].qty = 1;

    // strcpy(prod[2].product ,"Umbrella");
    // prod[2].price = 900;
    // prod[2].gst = 12;
    // prod[2].qty = 4;

    // strcpy(prod[3].product ,"Cigarette");
    // prod[3].price = 200;
    // prod[3].gst = 28;
    // prod[3].qty = 3;

    // strcpy(prod[4].product ,"Honey");
    // prod[1].price = 100;
    // prod[1].gst = 0;
    // prod[1].qty = 2;

    int cur_max = 0, max = 0, disc = 0.05;
    int disc_price;
    char max_product[20];

    for (int i = 0; i < n; i++)
    {
        if (prod[i].price > 500)
        {
            disc_price = prod[i].price - (prod[i].price * disc);
            cur_max = disc_price + (disc_price * (prod[i].gst / 100));
        }
        else
        {
            cur_max = prod[i].price + (prod[i].price * (prod[i].gst / 100));
        }

        if (cur_max > max)
        {
            max = cur_max;
            strcpy(max_product, prod[i].product);
        }
    }

    printf("%s", max_product);

    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        if (prod[i].price > 500)
        {
            disc_price = prod[i].price - (prod[i].price * disc);
            total = disc_price + (disc_price * (prod[i].gst / 100)) * prod[i].qty;
        }
        else
        {
            total = prod[i].price + (prod[i].price * (prod[i].gst / 100)) * prod[i].qty;
        }
    }

    printf("%d", total);
}