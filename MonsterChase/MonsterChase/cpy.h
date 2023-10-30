#pragma once

void cpy(char* destination, char source[50])
{
	for (int i = 0; i < 50; i++)
	{
		destination[i] = source[i];
	}
}

void cpy(char* destination, char source[50], int len)
{
	for (int i = 0; i < len; i++)
	{
		destination[i] = source[i];
	}
}