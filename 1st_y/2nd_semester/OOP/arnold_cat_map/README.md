Arnold's cat map là một phép biến đổi đơn giản, có tác dụng biến đổi dữ liệu từ một thứ có quy luật, có mẫu (như ảnh), thành một đống dữ liệu trong có vẻ hỗn độn, không có quy luật, ví dụ như hình sau.

![image](https://github.com/lhgiang040504/OOP/assets/121398839/d4444c8d-f58a-4d57-93e1-30b2f9cef523)

T (x, y) = T (i, j) với x = (2i + j) % m, y = (i + j) % m và T là hàm setter / getter tại vị trí (x, y). m là kích thước mảng / ma trận vuông. Hàm T này được thực thi m x m lần.

Một thuộc tính của phép biến đổi này là nó có chu kì, tức là sau k lần biến đổi, dữ liệu gốc sẽ được phục hồi. Nhiệm vụ của chúng ta trong bài này là tìm hệ số k (còn được gọi là period). Đối với dữ liệu khác nhau, k sẽ khác nhau.

Input: kích thước mảng và mảng hai chiều vuông.
Output: hệ số k.

  Input Format

int
int int int ...
int int int ...
...
int int int ...

  Constraints
Ma trận vuông

  Output Format

int

Sample Input 0

3
1 2 3
4 5 6
7 8 9

Sample Output 0

4
