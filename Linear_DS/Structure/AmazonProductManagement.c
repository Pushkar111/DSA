#include <stdio.h>
#include <stdlib.h>

struct Product
{
    int productId;
    char productName[100];
    char category[100];
    int quantity;
    int price;
};

void addProduct(struct Product p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Enter product id : ");
        scanf("%d", &p[i].productId);
        printf("Enter product name : ");
        scanf("%s", p[i].productName);
        printf("Enter category : ");
        scanf("%s", p[i].category);
        printf("Enter quantity : ");
        scanf("%d", &p[i].quantity);
        printf("Enter price : ");
        scanf("%d", &p[i].price);
    }
}

void display(struct Product p[], int n)
{
    int i;
    printf("\nProductId\tProductName\tCategory\tQuantity\tPrice");
    printf("\n--------------------------------------------------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t%s\t\t%s\t%d\t\t%d", p[i].productId, p[i].productName, p[i].category, p[i].quantity, p[i].price);
    }
}

int searchProductLinear(struct Product p[], int n, int productId)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (p[i].productId == productId)
        {
            return i;
        }
    }
    return -1;
}

int searchProductBinary(struct Product p[], int n, int productId)
{
    int min = 0, mid, max = n - 1;

    while (min <= max)
    {

        mid = (min + max) / 2;
        if (p[mid].productId == productId)
        {
            return mid;
        }
        else if (productId > p[mid].productId)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return -1;
}

void displayParticularProduct(struct Product p[], int index)
{
    if (index != -1)
    {
        printf("\nProductId\tProductName\tCategory\tQuantity\tPrice");
        printf("\n--------------------------------------------------------------------------------------------------------");
        printf("\n%d\t\t%s\t\t%s\t%d\t\t%d", p[index].productId, p[index].productName, p[index].category, p[index].quantity, p[index].price);
    }
}

void updateProduct(struct Product p[], int n, int productId)
{
    int index = -1;
    int choice, i;

    index = searchProductLinear(p, n, productId);

    if (index == -1)
    {
        printf("\nRecord not found!");
    }
    else
    {
        printf("Choose what you want to update : ");
        printf("\n--------------------------------------------------------");
        printf("\n1. productName");
        printf("\n2. category");
        printf("\n3. quantity");
        printf("\n4. price");
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter new productName : ");
            scanf("%s", p[index].productName);
            break;
        case 2:
            printf("Enter new category : ");
            scanf("%s", p[index].category);
            break;
        case 3:
            printf("Enter new quantity : ");
            scanf("%d", &p[index].quantity);
            break;
        case 4:
            printf("Enter new price : ");
            scanf("%d", &p[index].price);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}

void deleteProduct(struct Product p[], int *n, int productId)
{
    int index = -1;

    index = searchProductLinear(p, *n, productId);

    if (index == -1)
    {
        printf("\nRecord not found!");
    }
    else
    {
        for (int i = index; i < *n - 1; i++)
        {
            p[i] = p[i + 1];
        }
        (*n)--;
        printf("\nRecord deleted successfully!");
    }
}

int main()
{
    int index = -1;
    int productId;
    int choice;
    int i, n;

    printf("\nHow many product u want to add: ");
    scanf("%d", &n);

    struct Product p[n];

    while (1)
    {
        printf("\n\n=============================================================");
        printf("\n              Amazon Product Management System");
        printf("\n=============================================================");
        printf("\n1. Add Product");
        printf("\n2. display");
        printf("\n3. search By Linear Search");
        printf("\n4. search By Binary Search");
        printf("\n5. update");
        printf("\n6. delete");
        printf("\n7. exit");
        printf("\n=============================================================");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct(p, n);
            break;

        case 2:
            display(p, n);
            break;

        case 3:
            printf("\nEnter product id u want to search: ");
            scanf("%d", &productId);
            index = searchProductLinear(p, n, productId);
            if (index == -1)
            {
                printf("\nRecord not found!");
            }
            else
            {
                printf("\nRecord found!");
                displayParticularProduct(p, index);
            }
            break;

        case 4:
            for (i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (p[i].productId > p[j].productId)
                    {
                        struct Product temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                    }
                }
            }
            printf("\nEnter product id u want to search: ");
            scanf("%d", &productId);
            index = searchProductBinary(p, n, productId);
            if (index == -1)
            {
                printf("\nRecord not found!");
            }
            else
            {
                printf("\nRecord found!");
                displayParticularProduct(p, index);
            }
            break;

        case 5:
            printf("\nEnter product id u want to update: ");
            scanf("%d", &productId);
            updateProduct(p, n, productId);
            break;

        case 6:
            printf("\nEnter product id u want to delete: ");
            scanf("%d", &productId);
            deleteProduct(p, &n, productId);
            break;

        case 7:
            exit(0);
            break;
        }
    }
    return 0;
}