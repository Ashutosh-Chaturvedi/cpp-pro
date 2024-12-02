#include<iostream>

using namespace std;

void NumSquare() {
  cout << endl << endl;
  cout << "NUMBER SQUARE" << endl;

  int m;
  cout << "Enter the number of rows and columns: ";
  cin >> m;
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= m; i++) {
      cout << i << " ";
    }
    cout << endl;
  }

  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumSquare();
  else
    return;
}
void NumRectangle() {
  cout << endl << endl;
  cout << "NUMBER RECTANGLE" << endl;

  int m, n;
  cout << "Enter the number of rows: ";
  cin >> m;
  cout << "Enter the number to show in columns: ";
  cin >> n;
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
  }

  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumRectangle();
  else
    return;
}
void NumRhombus() {
  cout << endl << "NUMBER RHOMBUS" << endl;

  int n;
  cout << "Enter n:";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }

    for (int j = 1; j <= n; j++) {
      cout << j << " ";
    }
    cout << endl;
  }

  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumRhombus();
  else
    return;
}
void NumRight() {
  cout << endl << "NUMBER RIGHT ANGLED TRIANGLE" << endl;
  int m;
  cout << "Enter the number of rows: ";
  cin >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    cout << endl;
  }

  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumRight();
  else
    return;
}
void NumPlus() {
  cout << endl << "NUMBER PLUS" << endl;

  int n;
  cout << "Enter n:";
  cin >> n;
  if (n % 2 == 0)
    cout << endl
         << "Though the provided n isn't a odd number, so the PLUS isn't "
            "perfectly possible. "
         << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == (n / 2 + 1) || j == (n / 2 + 1))
        cout << 0 << " ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumPlus();
  else
    return;
}
void NumCross() {
  cout << endl << "NUMBER CROSS" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumCross();
  else
    return;
}
void NumHollowRec() {
  cout << endl << "NUMBER HOLLOW RECTANGLE" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumHollowRec();
  else
    return;
}
void NumPyramid() {
  cout << endl << "NUMBER PYRAMID" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    NumPyramid();
  else
    return;
}
void DiamondNum() {
  cout << endl << "NUMBER DIAMOND" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    DiamondNum();
  else
    return;
}
void Floyd() {
  cout << endl << "FLOYS NUMBER SERIES" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    Floyd();
  else
    return;
}
void Palindrome() {
  cout << endl << "PALINDROME SERIES" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    Palindrome();
  else
    return;
}
void Pascal() {
  cout << endl << "PASCAL SERIES" << endl;
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    Pascal();
  else
    return;
}
void numeric() {
  int n;
  cout << endl;
  cout << "NUMERIC PATTERN" << endl;
  cout << "1. Number Square" << endl;
  cout << "2. Number Rectangle" << endl;
  cout << "3. Number Rhombus" << endl;
  cout << "4. Number Right Angled Triangle " << endl;
  cout << "5. Number Plus" << endl;
  cout << "6. Number Cross" << endl;
  cout << "7. Number Hollow Rectangle" << endl;
  cout << "8. Number Pyramid" << endl;
  cout << "9. Diamond Number" << endl;
  cout << "10. Floyds Triangle" << endl;
  cout << "11. Palindromic Pattern" << endl;
  cout << "12. Pascal Triangle" << endl;
  cout << "0. Go Back" << endl << endl;
  cout << "Choose from the above options: ";
  cin >> n;
  if (n == 1)
    NumSquare();
  if (n == 2)
    NumRectangle();
  if (n == 3)
    NumRhombus();
  if (n == 4)
    NumRight();
  if (n == 5)
    NumPlus();
  if (n == 6)
    NumCross();
  if (n == 7)
    NumHollowRec();
  if (n == 8)
    NumPyramid();
  if (n == 9)
    DiamondNum();
  if (n == 10)
    Floyd();
  if (n == 11)
    Palindrome();
  if (n == 12)
    Pascal();
  if (n == 0)
    return;
  else
    numeric();
}

void StarSquare() {
  cout << endl << endl;
  cout << "STAR SQUARE" << endl;
  int m;
  cout << endl << "Enter the number of rows and columns: ";
  cin >> m;
  cout << endl;
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= m; i++) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarSquare();
  else
    return;
}
void StarRectangle() {
  cout << endl << endl;
  cout << "STAR RECTANGLE" << endl;
  int m, n;
  cout << "Enter the number of rows: ";
  cin >> m;
  cout << "Enter the number of columns: ";
  cin >> n;
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= n; i++) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarRectangle();
  else
    return;
}
void StarRhombus() {
  cout << endl << endl;
  cout << "STAR RHOMBUS" << endl;
  int n;
  cout << "Enter n:";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }
    for (int j = 1; j <= n; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarRhombus();
  else
    return;
}
void StarRight() {
  cout << endl << endl;
  cout << "STAR RIGHT ANGLED TRIANGLE" << endl;
  int m;
  cout << "Enter the number of rows: ";
  cin >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarRight();
  else
    return;
}
void StarPlus() {
  cout << endl << endl;
  cout << "STAR PLUS" << endl;
  int n;
  cout << "Enter n:";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == (n / 2 + 1) || j == (n / 2 + 1))
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarPlus();
  else
    return;
}
void StarCross() {
  cout << endl << endl;
  cout << "STAR CROSS" << endl;
  int n;
  cout << "Enter n:";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || i + j == n + 1)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarCross();
  else
    return;
}
void HollowRec() {
  cout << endl << endl;
  cout << "HOLLOW RECTANGLE" << endl;
  int n, m;
  cout << "Enter rows:";
  cin >> n;
  cout << "Enter columns:";
  cin >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 || i == n || j == 1 || j == m)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    HollowRec();
  else
    return;
}
void StarPyramid() {
  cout << endl << endl;
  cout << "STAR PYRAMID" << endl;
  int n, m;
  cout << "Enter the height of Pyramid: ";
  cin >> n;
  cout << "Enter the width of Pyramid: ";
  cin >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      cout << "* ";
    }
    for (int j = 2; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    StarPyramid();
  else
    return;
}
void DiamondStar() {
  cout << endl << endl;
  cout << "STAR DIAMOND" << endl;
  int n;
  cout << "Enter the size of diamond: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      cout << "* ";
    }
    for (int j = 2; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << "  ";
    }
    for (int j = n - 1; j >= i; j--) {
      cout << "* ";
    }
    for (int j = n - 2; j >= i; j--) {
      cout << "* ";
    }
    cout << endl;
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    DiamondStar();
  else
    return;
}
void ver(int n, int i, int m, int d) {
  if (m == 0)
    return;
  if (m % 2 == 0 && m != d) {
    for (int j = n - 2; j >= i; j--) {
      cout << "  ";
    }
  } else {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }
  }
  for (int j = 1; j <= 1; j++) {
    cout << "* ";
  }
  for (int j = 1; j <= i - 1; j++) {
    cout << "  ";
  }
  for (int j = 3; j <= i; j++) {
    cout << "  ";
  }
  for (int j = 1; j <= 1; j++) {
    if (i == j || i == n) {
      if (m == 1 && i != j)
        cout << "* ";
      else
        break;
    } else
      cout << "* ";
  }
  if (m % 2 == 0) {
    for (int j = n - 2; j >= i; j--) {
      cout << "  ";
    }
  } else {
    for (int j = n - 1; j >= i; j--) {
      cout << "  ";
    }
  }
  ver(n, i, m - 1, m);
}
void zig(int n, int m) {
  for (int i = 1; i <= n; i++) {
    ver(n, i, m, m);
    cout << endl;
  }
}
void ZigZag() {
  cout << endl << endl;
  cout << "STAR ZIG ZAG" << endl;
  int n;
  cout << "Enter the height: ";
  cin >> n;
  int m;
  cout << "Enter the number of zigs: ";
  cin >> m;
  int s;
  cout << "How many lines: ";
  cin >> s;
  for (int i = 1; i <= s; i++) {
    zig(n, m);
  }
  int ret;
  cout << "Wanna repeat?(choose 1): ";
  cin >> ret;
  if (ret == 1)
    ZigZag();
  else
    return;
}
void star() {
  int n;
  cout << endl;
  cout << "STAR PATTERN" << endl;
  cout << "1. Star Square" << endl;
  cout << "2. Star Rectangle" << endl;
  cout << "3. Star Rhombus" << endl;
  cout << "4. Star Right Angled Triangle " << endl;
  cout << "5. Star Plus" << endl;
  cout << "6. Star Cross" << endl;
  cout << "7. Hollow Rectangle" << endl;
  cout << "8. Star Pyramid" << endl;
  cout << "9. Diamond Star" << endl;
  cout << "10. Zig Zag" << endl;
  cout << "0. Go Back" << endl << endl;
  cout << "Choose from the above options: ";
  cin >> n;
  if (n == 1)
    StarSquare();
  if (n == 2)
    StarRectangle();
  if (n == 3)
    StarRhombus();
  if (n == 4)
    StarRight();
  if (n == 5)
    StarPlus();
  if (n == 6)
    StarCross();
  if (n == 7)
    HollowRec();
  if (n == 8)
    StarPyramid();
  if (n == 9)
    DiamondStar();
  if (n == 10)
    ZigZag();
  if (n == 0)
    return;
  else
    star();
}

void alpha() {}

void pattern() {
  int n;
  cout << "1. Star(symbol) Pattern " << endl;
  cout << "2. Numeric Pattern " << endl;
  cout << "3. Alphabetic Pattern " << endl;
  cout << "0. To Exit " << endl << endl;
  cout << "Choose the type of pattern you want to print: ";
  cin >> n;
  if (n == 1)
    star();
  else if (n == 2)
    numeric();
  else if (n == 3)
    alpha();
  else if (n == 0)
    return;
  // else
    // pattern();
  pattern();
}

int main(){
    cout << "\n Pattern Printing Program \n" << endl;
    pattern();
}