# WEASOLVE Final Test Cases

## Test Case 1 - Program Initialization

Input:

```txt
Run program
```

Expected output:

```txt
Header displays.
Menu displays.
Current weather is NOT SET.
Database records are loaded.
```

## Test Case 2 - Valid Weather Input

Input:

```txt
1
sunny
```

Expected output:

```txt
Weather updated to sunny.
```

## Test Case 3 - Invalid Weather Input

Input:

```txt
1
stormy
hot
rainy
```

Expected output:

```txt
stormy rejected.
hot rejected.
rainy accepted.
```

## Test Case 4 - View Recommendations

Precondition:

```txt
Current weather = rainy
```

Input:

```txt
2
```

Expected output:

```txt
Only rainy food records are displayed.
```

## Test Case 5 - Add Food Record

Input:

```txt
8
Food name: Test Food
Weather: cold
Budget: low
Price: 50
Restaurant: Test Canteen
Health note: Test note
```

Expected output:

```txt
New FoodItem is added with a new ID.
```

## Test Case 6 - Update Food Record

Input:

```txt
9
ID: 1
Field: price
New price: 85
```

Expected output:

```txt
Record 1 price changes to 85.
```

## Test Case 7 - Delete Food Record

Input:

```txt
10
ID: 1
yes
```

Expected output:

```txt
Record 1 is removed from active session.
```

## Test Case 8 - Save and Reopen

Input:

```txt
12
Run program again
6
```

Expected output:

```txt
Changes from add/update/delete remain in database.txt.
```

## Test Case 9 - Invalid Menu Input

Input:

```txt
abc
999
-1
2
```

Expected output:

```txt
abc rejected.
999 rejected.
-1 rejected.
2 accepted if within range.
```

## Test Case 10 - Empty Favorites

Input:

```txt
4
```

Expected output:

```txt
No favorite foods saved yet.
```
