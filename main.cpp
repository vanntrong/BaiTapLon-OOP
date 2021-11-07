#include "menu.h"

int main()
{
  listStudent newList;
  mainMenu(newList);
  // newList.addFirst();
  // newList.addFirst();

  // newList.showList();
  // newList.initList();
  // newList.addFirst();
  // newList.showList();
  // newList.removeHead();
  // newList.showList();
  // system("COLOR 70");
  system("\t\tpause");
}

// void SetWindowSize(SHORT width, SHORT height)
// {
//   HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

//   SMALL_RECT WindowSize;
//   WindowSize.Top = 0;
//   WindowSize.Left = 0;
//   WindowSize.Right = width;
//   WindowSize.Bottom = height;

//   SetConsoleWindowInfo(hStdout, 1, &WindowSize);
// }

// void GoTo(SHORT posX, SHORT posY)
// {
//   HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//   COORD Position;
//   Position.X = posX;
//   Position.Y = posY;

//   SetConsoleCursorPosition(hStdout, Position);
// }

// void exitMenu()
// {
//   char choose;
//   cout << "\n\tBạn có muốn thoát? (nhập y để thoát): ";
//   cin >> choose;
//   if (choose == 'y')
//   {
//     system("cls");
//   }
// }

// void inputMenu(listStudent &newList)
// {
//   system("cls");
//   int newSize;
//   GoTo(40, 2);
//   cout << "-------------------------------------\n";
//   GoTo(45, 3);
//   cout << "NHẬP THÔNG TIN SINH VIÊN\n";
//   cout << "\tNhập số lượng sinh viên ban đầu: ";
//   cin >> newSize;
//   for (int i = 0; i < newSize; i++)
//   {
//     newList.addLast();
//   }
//   cout << "\tHOÀN THÀNH!";
//   exitMenu();
// }

// void outputMenu(listStudent newList)
// {
//   system("cls");
//   GoTo(40, 2);
//   cout << "-------------------------------------\n";
//   GoTo(45, 3);
//   cout << "DANH SÁCH SINH VIÊN\n";
//   newList.showList();
//   cout << "\tHOÀN THÀNH!";
//   exitMenu();
// }

// void addMenu(listStudent &newList)
// {
//   system("cls");
//   GoTo(40, 2);
//   cout << "-------------------------------------\n";
//   GoTo(45, 3);
//   cout << "THÊM MỘT SINH VIÊN MỚI\n";
//   newList.addLast();
//   exitMenu();
// }

// void deleteMenu(listStudent &newList)
// {
//   int choose;

//   do
//   {
//     system("cls");
//     GoTo(40, 2);
//     cout << "-------------------------------------------\n";
//     GoTo(53, 3);
//     cout << "XÓA MỘT SINH VIÊN\n";
//     GoTo(40, 4);
//     cout << "-------------------------------------------\n";
//     GoTo(40, 5);
//     cout << "|     [1] Xóa Sinh Viên Theo Tên           |\n";
//     GoTo(40, 6);
//     cout << "|                                          |\n";
//     GoTo(40, 7);
//     cout << "|     [2] Xóa Sinh Viên Theo Mã Số         |\n";
//     GoTo(40, 8);
//     cout << "|                                          |\n";
//     GoTo(40, 9);
//     cout << "|     [3] Thoát                            |\n";
//     GoTo(42, 11);
//     cout << "  Nhập lựa chọn của bạn [1, 2, 3]: ";
//     cin >> choose;
//     switch (choose)
//     {
//     case 1:
//       // newList.removeByName();
//       break;
//     case 2:
//       newList.removeByMSSV();
//       break;
//     case 3:
//       system("cls");
//       break;
//     }
//   } while (choose != 3);
// }

// void mainMenu(listStudent &newList)
// {
//   system("COLOR 70");
//   SetConsoleOutputCP(65001); //hien thi ky tu dac biet
//   SetConsoleTitle("Quan Ly Sinh Vien");
//   SetWindowSize(200, 200);
//   int choose;
//   do
//   {
//     GoTo(40, 2);
//     cout << "QUẢN LÝ SINH VIÊN - UTC2 - BÀI TẬP LỚN OOP\n\n\n";
//     cout << "\t========================================================================================================\n";
//     cout << "\tNhập Danh Sách Sinh Viên    :   Nhấn phím 1\t|||\t";

//     cout << "Tìm Kiếm Sinh Viên              :    Nhấn phím 6\n\n";

//     cout << "\tXuất Danh Sách Sinh Viên    :   Nhấn phím 2\t|||\t";

//     cout << "Sắp Xếp Sinh Viên               :    Nhấn phím 7\n\n";

//     cout << "\tThêm Một Sinh Viên Mới      :   Nhấn phím 3\t|||\t";

//     cout << "Lọc Các Sinh Viên Bị Cảnh Báo   :    Nhấn phím 8\n\n";

//     cout << "\tSửa Thông Tin Một Sinh Viên :   Nhấn phím 4\t|||\t";

//     cout << "Xuất Ra File                    :    Nhấn phím 9\n\n";

//     cout << "\tXóa Một Sinh Viên           :   Nhấn phím 5\t|||\t";

//     cout << "Thoát Chương Trình              :    Nhấn phím 10\n\n";

//     cout << "\t=======================\n";
//     cout << "\tNhập Lựa Chọn Của Bạn: ";
//     cin >> choose;
//     switch (choose)
//     {
//     case 1:
//       inputMenu(newList);
//       break;
//     case 2:
//       outputMenu(newList);
//       break;
//     case 3:
//       addMenu(newList);
//       break;
//     case 4:
//       break;
//     case 5:
//       deleteMenu(newList);
//       break;

//     default:
//       break;
//     }
//   } while (choose != 10);
// }
