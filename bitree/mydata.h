#ifndef	__MYDATA__
#define __MYDATA__
#define	uint		unsigned int
#define	ulong		unsigned long
#define	schar		char    
#define	MAXEPOLL	11000
#define	DATASIZE		1024
#define	PORT			9889
int		iepollfd;
int		ilistenfd;
int		iMaxlink;
int 	iTimeout;

ulong	gSysTrace;
uint	gLoop=0;

typedef struct PublicData{
	uint	uiType;
	ulong	ulSysTrace;
	schar	sDate[8];
	schar	sTime[9];
	schar	sData[DATASIZE];
}
#endif