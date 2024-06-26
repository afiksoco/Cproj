#ifndef __MYDATE__
#define __MYDATE__

typedef struct
{
	int			day;
	int			month;
	int			year;
}Date;

void	initDate(Date* pDate);
int		checkDate(char* date, Date* pDate);
void	printDate(const Date* pDate);
int	compareDates(const void* v1, const void* v2);

#endif
