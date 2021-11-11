#include "Linked_List.h"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void SetWindowSize(SHORT width, SHORT height);
void GoTo(SHORT posX, SHORT posY);
void mainMenu(listStudent &newList);
void exitMenu();
void inputMenu(listStudent &newList);
void outputMenu(listStudent newList);
void addMenu(listStudent &newList);
void deleteMenu(listStudent &newList);
void editMenu(listStudent &newList);
void findMenu(listStudent &newlist);

void SetWindowSize(SHORT width, SHORT height)
{
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

  SMALL_RECT WindowSize;
  WindowSize.Top = 0;
  WindowSize.Left = 0;
  WindowSize.Right = width;
  WindowSize.Bottom = height;

  SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void GoTo(SHORT posX, SHORT posY)
{
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD Position;
  Position.X = posX;
  Position.Y = posY;

  SetConsoleCursorPosition(hStdout, Position);
}

void exitMenu()
{
  char choose;
  int j;
  cout << "\n\tNhấn phím bất kỳ để tiếp tục...";
  // cin >> choose;
  choose = getch();
  system("cls");
}

void inputMenu(listStudent &newList)
{
  system("cls");
  int newSize;
  GoTo(40, 2);
  cout << "-------------------------------------\n";
  GoTo(45, 3);
  cout << "NHẬP THÔNG TIN SINH VIÊN\n";
  cout << "\tNhập số lượng sinh viên ban đầu: ";
  cin >> newSize;
  for (int i = 0; i < newSize; i++)
  {
    newList.addLast();
  }
  cout << "\tHOÀN THÀNH!";
  exitMenu();
}

void outputMenu(listStudent newList)
{
  system("cls");
  GoTo(40, 2);
  cout << "-------------------------------------\n";
  GoTo(45, 3);
  cout << "DANH SÁCH SINH VIÊN\n";
  newList.showList();
  cout << "\tHOÀN THÀNH!";
  exitMenu();
}

void addMenu(listStudent &newList)
{
  system("cls");
  GoTo(40, 2);
  cout << "-------------------------------------\n";
  GoTo(45, 3);
  cout << "THÊM MỘT SINH VIÊN MỚI\n";
  newList.addLast();
  exitMenu();
}

void deleteMenu(listStudent &newList)
{
  int choose;
  do
  {
    system("cls");
    GoTo(40, 2);
    cout << "-------------------------------------------\n";
    GoTo(53, 3);
    cout << "XÓA SINH VIÊN\n";
    GoTo(40, 4);
    cout << "-------------------------------------------\n";
    GoTo(40, 5);
    cout << "|     [1] Xóa Sinh Viên Theo Tên           |\n";
    GoTo(40, 6);
    cout << "|                                          |\n";
    GoTo(40, 7);
    cout << "|     [2] Xóa Sinh Viên Theo Mã Số         |\n";
    GoTo(40, 8);
    cout << "|                                          |\n";
    GoTo(40, 9);
    cout << "|     [3] Thoát                            |\n";
    GoTo(42, 11);
    cout << "  Nhập lựa chọn của bạn [1, 2, 3] : ";
    cin >> choose;
    switch (choose)
    {
    case 1:
      system("cls");
      cout << "\n\t\t\n";
      newList.removeByName();
      exitMenu();
      // newList.removeByName();
      break;
    case 2:
      system("cls");
      cout << "\n\t\t\n";
      newList.removeByMSSV();
      exitMenu();
      // char n;
      // cout << "\t\tNhấn phím bất kì để tiếp tục...";
      break;
    case 3:
      system("cls");
      break;
    }
  } while (choose != 3);
}

void editMenu(listStudent &newList)
{
  int choose;
  system("cls");
  GoTo(40, 2);
  cout << "-------------------------------------------\n";
  GoTo(50, 3);
  cout << "SỬA THÔNG TIN SINH VIÊN\n";
  GoTo(40, 4);
  cout << "-------------------------------------------\n";
  GoTo(38, 5);
  Node *node = newList.findbyMSSV();
  if (node == NULL)
  {
    GoTo(40, 7);
    cout << "Không tìm thấy sinh viên này!!!\n";
    char newChoose;
    GoTo(40, 8);
    cout << "Bạn có muốn tiếp tục (Nhấn Y để tiếp tục) : ";
    cin >> newChoose;
    if (newChoose == 'y' || newChoose == 'Y')
    {
      editMenu(newList);
    }
    else
    {
      system("cls");
    }
  }
  else
  {
    do
    {
      system("cls");
      GoTo(40, 2);
      cout << "-------------------------------------------\n";
      GoTo(53, 3);
      cout << "SỬA THÔNG TIN SINH VIÊN\n";
      GoTo(40, 4);
      cout << "-------------------------------------------\n";
      GoTo(40, 5);
      cout << "|     [1] Sửa Mã Số Sinh Viên              |\n";
      GoTo(40, 6);
      cout << "|                                          |\n";
      GoTo(40, 7);
      cout << "|     [2] Sửa Tên Sinh Viên                |\n";
      GoTo(40, 8);
      cout << "|                                          |\n";
      GoTo(40, 9);
      cout << "|     [3] Sửa Ngày Sinh Sinh Viên          |\n";
      GoTo(40, 10);
      cout << "|                                          |\n";
      GoTo(40, 11);
      cout << "|     [4] Sửa Địa Chỉ Sinh Viên            |\n";
      GoTo(40, 12);
      cout << "|                                          |\n";
      GoTo(40, 13);
      cout << "|     [5] Sửa Điểm Sinh Viên               |\n";
      GoTo(40, 14);
      cout << "|                                          |\n";
      GoTo(40, 15);
      cout << "|     [6] Thoát                            |\n";
      GoTo(42, 17);
      cout << "  Nhập lựa chọn của bạn [1, 2, 3, 4, 5, 6] : ";
      cin >> choose;
      switch (choose)
      {
      case 1:
        system("cls");
        cout << "\n\t\t\n";
        newList.editMSSV(node);
        exitMenu();
        break;
      case 2:
        system("cls");
        cout << "\n\t\t\n";
        newList.editName(node);
        exitMenu();
        break;
      case 3:
        system("cls");
        cout << "\n\t\t\n";
        newList.editDateOfBirth(node);
        exitMenu();
        break;
      case 4:
        system("cls");
        cout << "\n\t\t\n";
        newList.editAddress(node);
        exitMenu();
        break;
      case 5:
        system("cls");
        cout << "\n\t\t\n";
        newList.editMark(node);
        exitMenu();
        break;
      case 6:
        system("cls");
        break;
      }
    } while (choose != 6);
  }
}

void findMenu(listStudent &newList)
{
  int choose;
  do
  {
    system("cls");
    GoTo(40, 2);
    cout << "-------------------------------------------\n";
    GoTo(53, 3);
    cout << "TÌM KIẾM SINH VIÊN\n";
    GoTo(40, 4);
    cout << "-------------------------------------------\n";
    GoTo(40, 5);
    cout << "|     [1] Tìm kiếm Sinh Viên Theo Tên      |\n";
    GoTo(40, 6);
    cout << "|                                          |\n";
    GoTo(40, 7);
    cout << "|     [2] Tìm kiếm Sinh Viên Theo Mã Số    |\n";
    GoTo(40, 8);
    cout << "|                                          |\n";
    GoTo(40, 9);
    cout << "|     [3] Thoát                            |\n";
    GoTo(42, 11);
    cout << "  Nhập lựa chọn của bạn [1, 2, 3] : ";
    cin >> choose;
    switch (choose)
    {
    case 1:
    {
      system("cls");
      GoTo(40, 2);
      cout << "-------------------------------------------\n";
      GoTo(53, 3);
      cout << "TÌM KIẾM SINH VIÊN\n";
      GoTo(40, 4);
      cout << "-------------------------------------------\n";
      GoTo(38, 5);
      Node *node = newList.findbyName();
      if (node == NULL)
      {
        GoTo(40, 7);
        cout << "Không tìm thấy sinh viên này!!!\n";
        char newChoose;
        GoTo(40, 8);
        cout << "Bạn có muốn tiếp tục (Nhấn Y để tiếp tục) : ";
        cin >> newChoose;
        if (newChoose == 'y' || newChoose == 'Y')
        {
          system("cls");
        }
        else
        {
          choose = 3;
        }
      }
      else
      {
        showNode(node);
      }
      system("cls");
      break;
    }
    case 2:
    {
      system("cls");
      GoTo(40, 2);
      cout << "-------------------------------------------\n";
      GoTo(53, 3);
      cout << "TÌM KIẾM SINH VIÊN\n";
      GoTo(40, 4);
      cout << "-------------------------------------------\n";
      GoTo(38, 5);
      Node *node = newList.findbyMSSV();
      if (node == NULL)
      {
        GoTo(40, 7);
        cout << "Không tìm thấy sinh viên này!!!\n";
        char newChoose;
        GoTo(40, 8);
        cout << "Bạn có muốn tiếp tục (Nhấn Y để tiếp tục) : ";
        cin >> newChoose;
        if (newChoose == 'y' || newChoose == 'Y')
        {
          system("cls");
        }
        else
        {
          choose = 3;
        }
      }
      else
      {
        showNode(node);
      }
      system("cls");
      break;
    }
    case 3:
    {
      system("cls");
      break;
    }
    }
  } while (choose != 3);
}

void mainMenu(listStudent &newList)
{
  system("COLOR 70");
  SetConsoleOutputCP(65001); //hien thi ky tu dac biet
  SetConsoleTitle("Quan Ly Sinh Vien");
  SetWindowSize(200, 200);
  int choose;
  do
  {
    GoTo(40, 2);
    cout << "QUẢN LÝ SINH VIÊN - UTC2 - BÀI TẬP LỚN OOP\n\n\n";
    cout << "\t========================================================================================================\n";
    cout << "\tNhập Danh Sách Sinh Viên    :   Nhấn phím 1\t|||\t";

    cout << "Tìm Kiếm Sinh Viên              :    Nhấn phím 6\n\n";

    cout << "\tXuất Danh Sách Sinh Viên    :   Nhấn phím 2\t|||\t";

    cout << "Sắp Xếp Sinh Viên               :    Nhấn phím 7\n\n";

    cout << "\tThêm Một Sinh Viên Mới      :   Nhấn phím 3\t|||\t";

    cout << "Lọc Các Sinh Viên Bị Cảnh Báo   :    Nhấn phím 8\n\n";

    cout << "\tSửa Thông Tin Một Sinh Viên :   Nhấn phím 4\t|||\t";

    cout << "Xuất Ra File                    :    Nhấn phím 9\n\n";

    cout << "\tXóa Một Sinh Viên           :   Nhấn phím 5\t|||\t";

    cout << "Thoát Chương Trình              :    Nhấn phím 10\n\n";

    cout << "\t=======================\n";
    cout << "\tNhập Lựa Chọn Của Bạn: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
      inputMenu(newList);
      break;
    case 2:
      outputMenu(newList);
      break;
    case 3:
      addMenu(newList);
      break;
    case 4:
      editMenu(newList);
      break;
    case 5:
      deleteMenu(newList);
      break;
    case 6:
      findMenu(newList);
      break;

    default:
      break;
    }
  } while (choose != 10);
}
