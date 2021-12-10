/*
  Yêu cầu: 1. Thêm chức năng kiểm tra mssv bị trùng: Thêm dòng 598-614, 65-83, 111-127 file menu.h
           2. Thêm chức năng tìm kiếm bằng chữ thường: Thêm dòng 337-352 file menu.h
  - Võ Văn Trọng: 6151071109
  - Bùi Nhật Huy:
  - Nguyễn Thiên Kha:
  - Nhóm 28
*/
#include "menu.h"

int main()
{
  listStudent newList;
  mainMenu(newList);
  cout << "\t";
  exitMenu();
}
