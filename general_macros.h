#pragma once

//繰り返し構文
#define REP(i, n)		for(int i = 0;i < (n);i++)
#define FORL(i,m,a,n)	for(int i = m;i <= (n);i+=a)	//CMDのfor/l
#define FORRL(i,m,a,n)	for(int i = m;i >= (n);i+=a)

//範囲チェック
#undef  IN
#define IN(a,n,b) ((a)<=(n)&&(n)<=(b))
