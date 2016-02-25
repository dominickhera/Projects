for (int i  = 0; i < 3; i++)
{
	//printf("doors foor room[%d]: [%d] = %c%d\n", index, i, rooms[index].doors[i].bearing, rooms[index].doors[i].offset);
​
		switch (rooms[index].doors[i].bearing)
		{
				case 'e':
					currentRoom[rooms[index].doors[i].offset][0] = '+';
					break;
				case 'w':
					currentRoom[rooms[index].doors[i].offset][roomX - 1] = '+';
					break;
				case 's':
					currentRoom[roomY - 1][rooms[index].doors[i].offset] = '+';
					break;
				case 'n':
					currentRoom[0][rooms[index].doors[i].offset] = '+';
					break;
				}
}