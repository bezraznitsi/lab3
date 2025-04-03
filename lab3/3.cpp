#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <ctime>
#include <vector>
using namespace std;


//=====================================���������� �������============================================
int** create_matrix(int m, int n) {
    int** matrix = new int* [m]; 
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void init(int m, int n, int** matrix) {
    cout << "������� �������� �������:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "������� [" << i << "][" << j << "] �������: ";
            cin >> matrix[i][j];
        }
    }
}

void initRandom(int m, int n, int** matrix) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0) || (i == m - 1) || (j == 1) || (j == n - 1)) {
                matrix[i][j] = rand() % 151 + 100;// ���� ����� ������ ����������, ����� ������� ����� �����, � ����� � 99% ������� ����� ����� 0
            }
            else
            {
                matrix[i][j] = rand() % 101;
            }
        }
    }
}

void show_matrix(int m, int n, int** matrix) {
    cout << "���� �������:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void delete_matrix(int m,int n, int** matrix){
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix; 
}

int minn(int m, int n, int** matrix) {
    int t = INT_MAX;
    for (int i = 0; i < m;++i) {
        for (int j = 0; j < n;++j) {
            if ((i == 0) || (i == m - 1) || (j == 0) || (j == n - 1)) {
                t = min(t, matrix[i][j]);
            }

        }
    }
        return t;
}


int value(int m, int n, int** matrix, int mn) {
    int v = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n;++j) {
            if (matrix[i][j] < mn) {
                v += mn - matrix[i][j];
            }
        }
    }
    return v;
}

//=====================================���������� �������� ������============================================
struct Node {
    int data;
    int i, j;
    Node* next;

    Node(int val, int row, int col) : data(val), i(row), j(col), next(nullptr) {}
};

Node* new_matrix(int m, int n,int** matrix) {
    Node* head = nullptr; // ������ ������
    Node* current = nullptr; // ������� ����

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            Node* newNode = new Node(matrix[i][j], i, j); // ��������� ������ ��� ���� �������, ������ ����� ��������� �� �� �������

            if (!head) {
                head = newNode; // ���� ������ ����, ������ ����� ���� �������
            }
            else {
                current->next = newNode;
            }
            current = newNode; 
        }
    }

    return head;
}


int minn_list(Node* head, int m, int n) {
    int t = INT_MAX;
    Node* current = head;
    while (current) {
        if (current->i == 0 || current->i == m - 1 || current->j == 0 || current->j == n - 1) {
            t = min(t, current->data); // ��������� �������
        }
        current = current->next; // ��������� � ���������� ����
    }

    return t;
}


int value_list(Node* head, int m, int n, int mn) {
    int v = 0;
    Node* current = head;

    while (current) {
        if (current->i > 0 && current->i < m - 1 && current->j > 0 && current->j < n - 1) {
            if (current->data < mn) {
                v += mn - current->data; 
            }
        }
        current = current->next;
    }

    return v;
}

void delete_linked_list(Node* head) {
    while (head) {
        Node* temp = head;      // ��������� ������� ����
        head = head->next;      // ��������� � ���������� ����
        delete temp;            // ������� ������� ����
    }
}
//=====================================���������� �������============================================

std::vector<std::vector<int>> create_matrix_vector(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    return matrix;
}

void init_vector(int m, int n, vector<vector<int>>& matrix1, int** matrix2) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
           matrix1[i][j] = matrix2[i][j];
        }
    }
}

int minn_vector(int m, int n, const std::vector<std::vector<int>>& matrix) {
    int t = INT_MAX;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                t = min(t, matrix[i][j]);
            }
        }
    }
    return t;
}

int value_vector(int m, int n, const std::vector<std::vector<int>>& matrix, int mn) {
    int v = 0;
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (matrix[i][j] < mn) {
                v += mn - matrix[i][j];
            }
        }
    }
    return v;
}

void clear_vector_matrix(vector<vector<int>>& matrix) {
    matrix.clear(); // ������� ��� �������� �������
}

 int main() {
    setlocale(LC_ALL, "");

    int m, n;
    double t1 = 0.0,t2 = 0.0,t3 = 0.0;
    int choice;

    do {
        cout << "������� ���������� ����� (M): ";
        cin >> m;
        cout << "������� ���������� �������� (N): ";
        cin >> n;

        if (m <= 0 || n <= 0) {
            cout << "������: ������� ������� ������ ���� �������������� �������. ���������� �����." << endl<<endl;
        }
    } while (m <= 0 || n <= 0);

    cout << endl << endl;

    double start = clock();
    int** q = create_matrix(m, n);
    double end = clock();
    t1 += (double)(end - start) / CLOCKS_PER_SEC;

    cout << "����� �������� ��������� �������?\n1) ������������� ���������� �������\n2) ������� (�� ������������� ��� ������� ������)\n>>> ";
    cin >> choice;
    bool y = false;

    while (!y) {
        switch (choice) {
        case 1:
            initRandom(m, n, q);
            y = true;
            break;
        case 2:
            init(m, n, q);
            y = true;
            break;
        default:
            cout << "�������������� �������. �������� �� ������������ ���������."<<endl;
            cout << ">>> ";
            cin >> choice;
            break;

        }
    }
    
    cout << endl;
    if (m < 20 && n < 20) {
        show_matrix(m, n, q);
    }
    else {
        cout << "������� ����� ������� �������, ������� ���������� �� �����" << endl;
    }

    cout << endl;
    start = clock();
    int mn = minn(m, n, q);
    int v1 = value(m, n, q ,mn);

    cout << "������� � ������� �������";
    cout << endl << "====================================" << endl;
    cout << "����������� ����� �� ��������: " << mn << endl;
    cout  <<"����� ����: " << v1 << endl;
    
 
    end = clock();
    t1 += (double)(end - start) / CLOCKS_PER_SEC;
    cout << "����������� �����: " << t1 << " sec"<<endl<<endl;
    cout << "������� � ������� �������� ������";
    cout << endl << "====================================" << endl;

    start = clock();
    Node* q2 = new_matrix(m, n,q);
    end = clock();
    t2 += (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int mn2 = minn_list(q2, m, n);
    cout << "����������� ����� �� ��������: " << mn2 << endl;

    int water_volume = value_list(q2, m, n, mn2);
    end = clock();
    t2 += (double)(end - start) / CLOCKS_PER_SEC;
    cout << "����� ����: " << water_volume << endl;
    cout << "����������� �����: " << t2 << " sec" << endl;
    cout << endl;

    start = clock();
    vector<std::vector<int>> q3 = create_matrix_vector(m, n);
    end = clock();
    t3 += (double)(end - start) / CLOCKS_PER_SEC;

    init_vector(m, n, q3,q);

    cout << "������� � ������� �������";
    cout << endl << "====================================" << endl ;
    //show_matrix_vector(m, n, matrix);
    start = clock();
    int mn3 = minn_vector(m, n, q3);
    cout << "����������� ����� �� ��������: " << mn3 << endl;

    water_volume = value_vector(m, n, q3, mn3);
    end = clock();
    t3 += (double)(end - start) / CLOCKS_PER_SEC;
    cout << "����� ����: " << water_volume << endl;
    cout << "����������� �����: " << t3 << " sec" << endl;

    delete_matrix(m, n, q);
    delete_linked_list(q2);
    clear_vector_matrix(q3);

    return 0;
    
}
