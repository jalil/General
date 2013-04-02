//Fractions class implementation

#import <Foundation/Foundation.h>
#import <stdio.h>

@interface Fraction: NSObject

-(void) factorFrac;
-(void) printFrac;
-(void) setNumerator: (int) n;
-(void) setDenominator: (int) d;
-(int) getNumerator;
-(int) getDenominator;
-(Fraction *) multiplyFracs: (Fraction *) otherFrac;
-(Fraction *) divideFracs: (Fraction *) otherFrac;
-(Fraction *) addFracs: (Fraction *) otherFrac;
-(Fraction *) subtractFracs: (Fraction *) otherFrac;

@end

@implementation Fraction
{
int numerator;
int denominator;
}

-(void) factorFrac
{
	int num = [self getNumerator];
	int den = [self getDenominator];

	for (int idx = 1; idx < 100; idx++)
	{
		if (num % idx == 0 && den % idx == 0)
		{
			[self setNumerator: num / idx];
			[self setDenominator: den / idx];
		}
	}
	
	[self setNumerator: numerator];
	[self setDenominator: denominator];
}


-(void) printFrac
{
	NSLog(@"\nThe fraction is %i/%i.", numerator, denominator);
}

-(void) setNumerator: (int) n
{
	numerator = n;
}

-(void) setDenominator: (int) d
{
	denominator = d;
}

-(int) getNumerator
{
	return numerator;
}

-(int) getDenominator
{
	return denominator;
}

-(Fraction *) multiplyFracs: (Fraction *) otherFrac
{
	int new_Numerator;
	int new_Denominator;

	Fraction *newFrac = [[Fraction alloc] init];

	new_Numerator = [self getNumerator] * [otherFrac getNumerator];
	new_Denominator = [self getDenominator] * [otherFrac getDenominator];

	[newFrac setNumerator: new_Numerator];
	[newFrac setDenominator: new_Denominator];
	[newFrac factorFrac];

	return newFrac;
}

-(Fraction *) divideFracs: (Fraction *) otherFrac
{
	int new_Numerator;
	int new_Denominator;

	Fraction *newFrac = [[Fraction alloc] init];

	new_Numerator = [self getNumerator] * [otherFrac getDenominator];
	new_Denominator = [self getDenominator] * [otherFrac getNumerator];

	[newFrac setNumerator: new_Numerator];
	[newFrac setDenominator: new_Denominator];
	[newFrac factorFrac];

	return newFrac;
}

-(Fraction *) addFracs: (Fraction *) otherFrac
{
	int new_Numerator;
	int new_Denominator;
	
	Fraction *newFrac = [[Fraction alloc] init];

	new_Numerator = ([self getNumerator] * [otherFrac getDenominator]) + ([self getDenominator] * [otherFrac getNumerator]);
	new_Denominator = [self getDenominator] * [otherFrac getDenominator];

	[newFrac setNumerator: new_Numerator];
	[newFrac setDenominator: new_Denominator];
	[newFrac factorFrac];

	return newFrac;
}

-(Fraction *) subtractFracs: (Fraction *) otherFrac
{
	int new_Numerator;
	int new_Denominator;

	Fraction *newFrac = [[Fraction alloc] init];

	new_Numerator = ([self getNumerator] * [otherFrac getDenominator]) - ([self getDenominator] * [otherFrac getNumerator]);
	new_Denominator = [self getDenominator] * [otherFrac getDenominator];

	[newFrac setNumerator: new_Numerator];
	[newFrac setDenominator: new_Denominator];
	[newFrac factorFrac];

	return newFrac;
}
@end


int main(int argc, const char * argv[])
{
	@autoreleasepool
	{
		Fraction *frac1 = [[Fraction alloc] init];
		Fraction *frac2 = [[Fraction alloc] init];
		Fraction *frac3 = [[Fraction alloc] init];

		[frac1 setNumerator: 1];
		[frac1 setDenominator: 2];
		
		[frac2 setNumerator: 1];
		[frac2 setDenominator: 4];
	
		printf("\nFRACTION 1:\n");
		[frac1 printFrac];

		printf("\nFRACTION 2:\n");
		[frac2 printFrac];


		frac3 = [frac1 addFracs: frac2];

		printf("\nADDITION:\n");
		[frac3 printFrac];

		frac3 = [frac1 subtractFracs: frac2];

		printf("\nSUBTRACTION:\n");
		[frac3 printFrac];

		frac3 = [frac1 multiplyFracs: frac2];

		printf("\nMULTIPLICATION:\n");
		[frac3 printFrac];

		frac3 = [frac1 divideFracs: frac2];

		printf("\nDIVISION:\n");
		[frac3 printFrac];

	}
	return 0;
}


