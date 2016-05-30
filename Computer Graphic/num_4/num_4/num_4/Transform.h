value struct TPoint
{
	float x, y;
};

value struct TLine
{
	TPoint start, end;
	System::String^ name;
};

#define M 3
typedef float Vec[M];
typedef float Mat[M][M];

extern Mat T;

void times( Mat a, Mat b, Mat c ); // ��������� ������� �� �������
void timesMatVec( Mat a, Vec b, Vec c ); // ��������� ������� �� ������
void set( Mat a, Mat b ); // ������� �� ������� � �������
void point2vec( TPoint a, Vec b ); // �������������� ����� � ������
void vec2point( Vec a, TPoint &b ); // �������������� ������� � �����
void makeHomogenVec( float x, float y, Vec c ); // �������������� ��������� � ������
void unit( Mat a ); // �������������� �������� ������� � ���������
void move( float t_x, float t_y, Mat c ); // ������� �������������� ��������
void rotate( float centre_x, float centre_y, float phi, Mat c ); // ������� �������������� ��������
void scale( float s_x, float s_y, Mat c ); // ������� �������������� ���������������
void reflectVertical( Mat a ); // ������� �������������� ��������� �� ���������
void reflectHorizontal( Mat a ); // ������� �������������� ��������� �� �����������
void frame( float v_x, float v_y, float v_cx, float v_cy, 
	float w_x, float w_y, float w_cx, float w_cy, 
	Mat c ); // ������� �������������� ��������� ����� �� ��������� �� � �������� ��
