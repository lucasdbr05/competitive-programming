def fuga(h,p,f,d):
	H = (h-f)/d
	P = (p-f)/d
	
	H+= 16 if H<0 else 0
	P+= 16 if P<0 else 0 
	
	return 'S' if H<P else 'N'

def main():
    print(fuga(h, p, f, d))
if __name__ == "__main__":
    h, p, f, d = map(int, input().split())
    main()