#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char*	itemName;
	int		quantity;
	float	price;
	float	amount;
} sItem;

void fReadItem(sItem*);
void fPrintItem(sItem*);
void deleteItem(sItem*);

int main()
{
	sItem* example = calloc(1, sizeof(sItem));
	fReadItem(example);
	fPrintItem(example);
	deleteItem(example);
	return 0;
}

void fReadItem(sItem* item)
{
	char temp[50];
	//memset(&temp, 0, 50);
	printf("Type in item details:\n");
	
	printf("Item name: ");
	fgets(temp, 49, stdin);
	fflush(stdin);
	size_t templen = strlen(temp);
	item->itemName = calloc(templen, sizeof(char));
	memcpy(item->itemName, temp, templen);
	item->itemName[templen - 1] = '\0';

	printf("Item quantity: ");
	scanf_s("%d", &item->quantity);
	getchar();

	printf("Item unit price: ");
	scanf_s("%f", &item->price);
	getchar();

	item->amount = item->price * item->quantity;

	return;
}

void fPrintItem(sItem* item)
{
	printf("Item information.\nItem name: %s\nItem quantity: %d\nItem unit price: %f\nTotal worth: %f\n", item->itemName, item->quantity, item->price, item->amount);
	return;
}

void deleteItem(sItem* item)
{
	free(item->itemName);
	return;
}