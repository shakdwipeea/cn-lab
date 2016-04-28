#include<stdio.h>
#include<unistd.h>

int generator_matrix[4][7] = {
	0, 1, 1, 1, 0, 0, 0,
	1, 0, 1, 0, 1, 0, 0,
	1, 1, 0, 0, 0, 1, 0,
	1, 1, 1, 0, 0, 0, 1
};

int hamming_matrix[3][7] = {
	1, 0, 0, 0, 1, 1, 1,  
	0, 1, 0, 1, 0, 1, 1,
 	0, 0, 1, 1, 1, 0, 1
};

int main(int argc, char const *argv[])
{
	int data[4], received[7];
	int encoded[7] = {0};
	int i = 0, j = 0;
	int syndrome[3] = {0};

	for (i = 0; i < 4; ++i)
	{
		scanf("%d", &data[i]);
	}

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 7; ++j)
		{
			encoded[j] += data[i] * generator_matrix[i][j];
		}
	}

	for (i = 0; i < 7; ++i)
	{
		encoded[i] = encoded[i] % 2;
	}

	printf("%s\n", "encoded data");
	for (i = 0; i < 7; ++i)
	{
		printf("%d\n", encoded[i]);
	}

	
	printf("%s\n", "Enter received data");
	for (i = 0; i < 7; i++)
	{
		scanf(" %d", &received[i]);
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 7; ++j)
		{
			syndrome[i] +=	hamming_matrix[i][j] * received[j];
		}
	}

	for (i = 0; i < 3; ++i)
	{
		syndrome[i] = syndrome[i] % 2;
	}

	for (i = 0; i < 7; )
	{
		if (syndrome[0] == hamming_matrix[0][i] &&
			syndrome[1] == hamming_matrix[1][i] &&
			syndrome[2] == hamming_matrix[2][i])
		{
			break;
		}
	}

	if (i == 7)
	{
		printf("%s\n", "error free data");
		return 0;
	}

	printf("%s %d\n", "Error bit is", i + 1);
	received[i] = !received[i];

	printf("%s\n", "Error free data is");
	for (i = 0; i < 7; ++i)
	{
		printf("%d\n", received[i]);
	}

	return 0;
}
