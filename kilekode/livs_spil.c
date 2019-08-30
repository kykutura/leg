#include <stdio.h>
#include <stdlib.h>
int rund(int h,int l)
{
	if(h<0)
		h=l-h+1;
	return h
}

void mxpr(int h, int l ,int bane[][l])
{
	for(int tel=0; tel<l; tel++)
	{
		for(int tel2=0; tel2<h; tel2++)
		{
			char gh = bane[tel][tel2];
			printf("%c",gh);
		}
	printf("\n");
	}

}
void fymx(int h, int l ,int bane[][l], char pl)
{
        for(int tel=0; tel<l; tel++)
        {
                for(int tel2=0; tel2<h; tel2++)
                {
			bane[tel][tel2]=pl;
                }
        }

}
void naeste(int h, int l ,int bane[][l],int bane2[][l], char pl)
{
	for(int tel=0; tel<l; tel++)
        {
		for(int tel2=0; tel2<h; tel2++)
                {
			int naboer = 0;
                        for(int tel3=-1; tel<2; tel3++)
			{
				for(int tel4=-1; tel4<2; tel3++)
				{
					if(tel3 != tel4 && tel3 != 0)
					{
						if(bane[rund(( tel + tel3 ) % l,l)][rund(( tel2 + tel4) % h,h)]==pl)
							naboer++;

					}

				 }
			
				bane2[tel][tel2]=pl;
			if(bane[tel][tel2==pl])
			{
				if(naboer==2)
					bane2[tel][tel2]=pl;
				
				if(naboer<2)
					bane2[tel][tel2]="#";
				
				else
					bane2[tel][tel2] = "#"



			}
			else
				if(naboer >2)
					bane2[tel][tel2]=pl;
			}

                }                       
	}
}



int main()
{
int info[7];
char hg = '#';
printf("skrin hoejten,laengten,spire ");
scanf("%i,%i,%i", info, info+1, info+2 );
printf("%i %i %i \n",info[0], info[1], info[2]);
int ban[info[0]][info[1]];
int ban2[info[0]][info[1]];

fymx(info[0], info[1], ban, hg);
mxpr(info[0], info[1], ban);
return 0;
}
