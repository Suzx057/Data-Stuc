#include <iostream>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int serviceTime;
};

void push(Process stack[], int &top, Process p) {
    stack[++top] = p;  // เพิ่ม process ลงใน stack
}

Process pop(Process stack[], int &top) {
    return stack[top--];  // นำ process ล่าสุดออกจาก stack
}

int main() {
    int N;
    cout << "Enter the number of processes: ";
    cin >> N;

    Process processes[100];  // ใช้สำหรับจัดเก็บข้อมูล process
    Process stack[100];      // ใช้เป็น stack สำหรับจัดการกระบวนการ
    int top = -1;            // ใช้เก็บตำแหน่งบนสุดของ stack

    for (int i = 0; i < N; i++) {
        cout << "Enter PID, arrival time, and service time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrivalTime >> processes[i].serviceTime;
    }

    int time = 0;
    int index = 0;

    while (index < N || top >= 0) {
        // ตรวจสอบว่า process ใหม่เข้ามาหรือไม่
        if (index < N && processes[index].arrivalTime == time) {
            push(stack, top, processes[index]);
            index++;
        }

        if (top >= 0) {
            Process current = pop(stack, top);  // เลือก process ล่าสุดที่ถูกเพิ่มเข้ามา

            while (current.serviceTime > 0) {  // ทำงานจนกว่าจะเสร็จ
                cout << "Process " << current.pid << " : " << current.serviceTime << endl;
                current.serviceTime--;
                time++;
                
                // เช็คว่ามี process ใหม่เข้ามาในช่วงนี้หรือไม่
                if (index < N && processes[index].arrivalTime == time) {
                    push(stack, top, processes[index]);  // เพิ่ม process ใหม่ลงใน stack
                    index++;
                }
            }
        } else {
            time++;
        }
    }

    return 0;
}