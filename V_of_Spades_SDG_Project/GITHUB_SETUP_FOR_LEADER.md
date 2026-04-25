# GitHub Setup Guide for WEASOLVE Leader - Eurie V. Paulino

## Official project lead

```txt
Paulino, Eurie V.
```

Only the project lead should create the repository.

## 1. Create repository

Repository name:

```txt
V_of_Spades_SDG_Project
```

Recommended visibility:

```txt
Private or Public, depending on professor preference.
```

If private, invite all members and the professor account.

## 2. Upload initial files

Upload:

```txt
.gitignore
README.md
CODE/
INPUT_DATA/
DOCUMENTATION/
```

## 3. Invite collaborators

Invite:

```txt
Paulino, Eurie V. - repository owner / project lead
Alvarez, Jerome Oliver P. - collaborator
Beli, Jhon Rey B. - collaborator
Domingo, Quirc Edrian P. - collaborator
Malabanan, Justine Lyle R. - collaborator
jlrn-rph - required professor collaborator
```

## 4. Create branches

```txt
feature/main-menu-integration
feature/food-item-class
feature/crud-manager
feature/file-handling-database
feature/recommendation-validation-report
```

## 5. Commit message format

Use clear commit messages:

```txt
Add FoodItem class skeleton
Implement FoodItem getters and setters
Add database with 20 records
Implement loadFromFile function
Implement view all and search functions
Implement delete food record
Add weather recommendation logic
Fix invalid menu input handling
Update README usage instructions
```

## 6. Pull request rule

Each member should:

```txt
1. Work only on assigned branch.
2. Commit their own changes.
3. Open pull request to main.
4. Explain what they changed.
5. Paulino reviews before merging.
```

## 7. Integration rule

Paulino should not merge a pull request until it compiles and the changed feature has been tested.


Never merge broken code into main.

Before merge:

```bash
g++ CODE/main.cpp CODE/FoodItem.cpp CODE/FoodManager.cpp CODE/InputValidator.cpp -o weasolve
```

If it does not compile, do not merge yet.
