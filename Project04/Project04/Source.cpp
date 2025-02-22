#include "Admin.h"
#include "Display.h"
#include "HangHoa.h"

using namespace std;

int main() {
    //Setting console
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 20;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) { SetWindowPos(hwnd, 0, 0, 0, 800, 500, SWP_SHOWWINDOW | SWP_NOMOVE); }

    //Handle
    QLAdmin qlAd; qlAd.loadData("./Admin.txt");
    QLHangHoa qlHH; qlHH.loadData("./HangHoa.txt");

    bool isLoggedIn = false;
    short route = 1; // 1: menu, 2: login, 3: menu QL,
    short cntLogin = 0;

    while (true) {
        if (route == 9) exit(0);
        system("CLS");
        short vs = 1;

        switch (route) {
        case 1: //Route Menu
            box(20, 0, 30, 1, "Thong tin hang hoa", false);
            box(20, 2, 30, 1, "Tim kiem hang hoa", true);
            box(20, 4, 30, 1, "Dat Hang", true);
            box(20, 6, 30, 1, "Quan li", true);
            gotoxy(20 + 19, 1);

            while (true) {
                char chose = _getch();
                switch (vs) {
                case 1:
                    if (chose == '\t') { vs = 2; gotoxy(20 + 18, 3); continue; }
                    else if (chose == IN::IN_RET) {  }
                    break;
                case 2:
                    if (chose == '\t') { vs = 3; gotoxy(20 + 9, 5); continue; }
                    else if (chose == IN::IN_RET) {  }
                    break;
                case 3:
                    if (chose == '\t') { vs = 4; gotoxy(20 + 8, 7); continue; }
                    else if (chose == IN::IN_RET) {  }
                    break;
                case 4:
                    if (chose == '\t') { vs = 1; gotoxy(20 + 19, 1); continue; }
                    else if (chose == IN::IN_RET) { 
                        route = 2;
                        cntLogin = 0;
                    }
                    break;
                default:
                    break;
                }
                break;
            }
            break;
        case 2: // Route Login
            if (!isLoggedIn) {
                gotoxy(8, 0);
                cout << "*************** Dang nhap he thong ***************";
                for (short i = 1; i < 16; i++) {
                    gotoxy(8, i);
                    cout << "*";
                    gotoxy(57, i);
                    cout << "*";
                }
                gotoxy(8, 16);
                cout << "**************************************************";

                string user;
                string password;
                box(12, 4, 40, 1, "User: ", false);
                box(12, 6, 40, 1, "Password: ", true);
                box(42, 10, 10, 1, "Continue", false);
                box(12, 10, 6, 1, "Back", false);
                gotoxy(12 + 7, 5);
                while (true) {
                    char inp = _getch();
                    if (inp == 27) { //EXC
                        route = 1;
                        break;
                    }
                    switch (vs)
                    {
                    case 1:
                        if (inp == '\t' || inp == IN::IN_RET) {
                            vs = 2; 
                            short wvs = password.length() >= 25 ? 25 : password.length();
                            gotoxy(12 + 11 + wvs, 7);
                            continue;
                        }
                        else { takeInput(user, inp, false, 30); continue; }
                        break;
                    case 2: 
                        if (inp == '\t') {
                            vs = 3; gotoxy(42 + 9, 11); continue;
                        }
                        else if (inp == IN::IN_RET) {
                            isLoggedIn = qlAd.checkAuth(user, password);
                            if (!isLoggedIn) {
                                cntLogin++;
                                if (cntLogin > 3) { route = 1; break; }
                                gotoxy(12, 14);
                                cout << "Tai khoan hoac mat khau khong dung!";
                                gotoxy(12, 15);
                                cout << "bam \"Enter\" de tiep tuc";
                                while (true) {
                                    char ent = _getch();
                                    if (ent == IN::IN_RET) break;
                                }
                            }
                        }
                        else { takeInput(password, inp, true, 25); continue; }
                        break;
                    case 3:
                        if (inp == '\t') {
                            vs = 4; gotoxy(12 + 5, 11); continue;
                        }
                        else if (inp == IN::IN_RET) {
                            isLoggedIn = qlAd.checkAuth(user, password);
                            if (!isLoggedIn) {
                                cntLogin++;
                                if (cntLogin > 3) { route = 1; break; }
                                gotoxy(12, 14);
                                cout << "Tai khoan hoac mat khau khong dung!";
                                gotoxy(12, 15);
                                cout << "bam \"Enter\" de tiep tuc";
                                while (true) {
                                    char ent = _getch();
                                    if (ent == IN::IN_RET) break;
                                }
                            }
                        }
                        break;
                    case 4:
                        if (inp == '\t') {
                            vs = 1;
                            short wvs = user.length() >= 30 ? 30 : user.length();
                            gotoxy(12 + 7 + wvs, 5);
                            continue;
                        }
                        else if (inp == IN::IN_RET) {
                            route = 1; break;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                }
            }
            else route = 3;
            break;
        case 3: // Menu Quan Li
            box(20, 0, 30, 1, "Xu li don hang", false);
            box(20, 2, 30, 1, "Quan li don hang", true);
            box(20, 4, 30, 1, "Menu", true);
            box(20, 6, 30, 1, "Log out", true);
            gotoxy(20 + 15, 1);
            while (true) {
                char chose = _getch();
                switch (vs) {
                case 1:
                    if (chose == '\t') { vs = 2; gotoxy(20 + 17, 3); continue; }
                    else if (chose == IN::IN_RET) { }
                    break;
                case 2:
                    if (chose == '\t') { vs = 3; gotoxy(20 + 5, 5); continue; }
                    else if (chose == IN::IN_RET) { }
                    break;
                case 3:
                    if (chose == '\t') { vs = 4; gotoxy(20 + 8, 7); continue; }
                    else if (chose == IN::IN_RET) {
                       route = 1;
                    }
                    break;
                case 4:
                    if (chose == '\t') { vs = 1; gotoxy(20 + 15, 1); continue; }
                    else if (chose == IN::IN_RET) { 
                        isLoggedIn = false;
                        route = 2;
                    }
                    break;
                default:
                    break;
                }
                break;
            }
            break;
        default:        
            break;
        }
    }

    return 0;
}