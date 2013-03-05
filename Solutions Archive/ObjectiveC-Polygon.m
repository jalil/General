//End of chapter questions continued

#import <Foundation/Foundation.h>
#import <math.h>
#import <stdio.h>
#import <stdlib.h>

@interface Reggon: NSObject
-(void) setSideL: (int) sl;
-(void) setNumVertices: (int) nv;
-(int) getSideL;
-(int) getPerimeter;
-(double) getArea;
-(int) getNumSides;
-(NSString *) getPolyClass;
-(void) print;
-(void) init_props;
@end

@implementation Reggon
{
	int sideLength;
	int numVertices;
	int numSides;
	int perimeter;
	int area;
	NSString *strClassification;
}
-(void) init_props
{
	numSides = [self getNumSides];
	perimeter = [self getPerimeter];
	area = [self getArea];
	strClassification = [self getPolyClass];
}

-(void) setSideL: (int) sl
{
	sideLength = sl;
}

-(void) setNumVertices: (int) nv
{
	numVertices = nv;
}

-(int) getSideL
{
	return sideLength;
}

-(int) getNumSides
{
	if (numVertices != 1 && numVertices != 2)
	{
		return numVertices;
	}
	else
	{
		return numVertices - 1;
	}
}

-(int) getPerimeter
{
	return numSides * sideLength;
}

-(double) getArea
{
	if (numSides >= 2)
	{
		return (((sideLength * sideLength) * numSides)/(4 * tan(M_PI / numSides)));  	
	}
	else
	{
		return 0.0;
	}
}

-(NSString *) getPolyClass
{
	NSMutableString *strPolyClass = [NSMutableString stringWithString:@""];

	switch (numSides)
	{
		case 0:

		case 1:

		case 2:
			[strPolyClass appendString: @"No polygon with that number of points exists."];
			break;

		case 3:
			[strPolyClass appendString: @"Triangle"];
			break;

		case 4:
			[strPolyClass appendString: @"Square"];
			break;

		case 5:
			[strPolyClass appendString: @"Pentagon"];
			break;

		case 6:
			[strPolyClass appendString: @"Hexagon"];
			break;

		case 7:
			[strPolyClass appendString: @"Heptogon"];
			break;

		case 8:	
			[strPolyClass appendString: @"Octagon"];
			break;

		case 9:
			[strPolyClass appendString: @"Nonagon"];
			break;
		
		default:
		//	[strPolyClass stringByAppendingFormat: @"%i", numSides];
			[strPolyClass appendString: @"-gon"];
		//	NSString *strPolyClass_return = @"%@-gon", numSides;
		//	strPolyClass = [NSMutableString stringWithString: strPolyClass_return];
			break;
	
	}
	return strPolyClass;
}
	
-(void) print
{
	if (numSides < 10)
	{
		printf("This polygon is a(n):\n%s with %i vertices, %i sides of length %i, a perimeter of %i, and an area of %d square units.\n", [strClassification UTF8String], numVertices, numSides, sideLength, perimeter, area); 
	}
	
	else if (numSides >= 10)
	{
		printf("This polygon is a(n):\n%i%s with %i vertices, %i sides of length %i, a perimeter of %i, and an area of %d square units.\n", numSides, [strClassification UTF8String], numVertices, numSides, sideLength, perimeter, area);
	}
}


@end

int main(int argc, const char * argv[])
{
	@autoreleasepool
	{
		char str_numVertices[256];
		char str_SideL[256];
		int int_numVertices;
		int int_SideL;
		//char char_UsrContinue = 'y'; 
		Reggon *myGon = [[Reggon alloc] init];

		printf("\nWelcome to the polygon classifier!");
		 	
		printf("\nPlease input the number of vertices: ");
		scanf("%s",str_numVertices);
		//fgets(char_usrInput, 256, stdin);
		int_numVertices = atoi(str_numVertices);	

		[myGon setNumVertices: int_numVertices];
		
		printf("Please give me the sidelength: ");
		//fgets(char_usrInput, 256, stdin);
		scanf("%s", str_SideL);
		int_SideL = atoi(str_SideL);

		[myGon setSideL: int_SideL];
		[myGon init_props];
		[myGon print];
			
		//printf("Would you like to continue with another polygon? [y/n]");
		//fgets(char_UsrContinue, 1, stdin);
		//scanf("%c", char_UsrContinue);		

		 
	}
	return 0;
}



