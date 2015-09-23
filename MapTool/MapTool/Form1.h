#pragma once
#include "Mymap.h"
#include <cmath>
#define PI 3.14159265358979323846
/*
  Author : lcm
  Date : 2014.12.16
  读取osm文件并画出地图
  拓展功能：选取图上任意两点找出最短路
*/

namespace MapTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Drawing::Bitmap^ bmp;
		System::Drawing::Pen^ myPen,^motorway_pen,^motorway_link_pen,^trunk_pen,^primary_pen,^secondary_pen,^tertiary_pen,^unclassified_pen,^service_pen;
		System::Drawing::Pen^ track_pen,^footway_pen,^waterway_pen,^other_pen,^undefined_pen,^shortpath_pen;
		System::Drawing::Font^ myFont;
		System::Drawing::SolidBrush^ bru1;
		Mymap * map;
		ShortestPath * path;
		bool pic_mouse;
		int curX,curY;
		int default_pic_width; //保存默认的picture_map控件大小
		int default_pic_height;

		bool ShowName;
		bool ShowFlag;

		bool set_begin,set_end;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  BeginItem;
	private: System::Windows::Forms::ToolStripMenuItem^  EndItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  PathSelect2;

	private: System::Windows::Forms::RadioButton^  PathSelect1;

	private: System::Windows::Forms::ToolStripMenuItem^  FindItem;

		System::Drawing::Pen^ SelectPen(int flag) //画笔选择函数
		{
			switch(flag)
			{
			case WAY_MOTORWAT: return motorway_pen;
			case WAY_MOTORWAT_LINK: return motorway_link_pen;
			case WAY_PRIMARY: return primary_pen;
			case WAY_PRIMARY_LINK: return primary_pen;
			case WAY_TRUNK: return trunk_pen;
			case WAY_SECONDARY: return secondary_pen;
			case WAY_TERTIARY: return tertiary_pen;
			case WAY_UNCLASSIFIED: return unclassified_pen;
			case WAY_SERVICE: return service_pen;
			case WAY_TRACK: return track_pen;
			case WAY_FOOTWAY: return footway_pen;
			case WAY_WATERWAY: return waterway_pen;
			case WAY_OTHER: return other_pen;
			default:
				return undefined_pen;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  picture_map;
	protected: 

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  m_width;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->picture_map = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->BeginItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EndItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->FindItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->m_width = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->PathSelect1 = (gcnew System::Windows::Forms::RadioButton());
			this->PathSelect2 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_map))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->picture_map);
			this->panel1->Location = System::Drawing::Point(23, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(760, 598);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &Form1::panel1_Click);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			// 
			// picture_map
			// 
			this->picture_map->BackColor = System::Drawing::Color::White;
			this->picture_map->ContextMenuStrip = this->contextMenuStrip1;
			this->picture_map->Location = System::Drawing::Point(1, 0);
			this->picture_map->MaximumSize = System::Drawing::Size(999999, 999999);
			this->picture_map->Name = L"picture_map";
			this->picture_map->Size = System::Drawing::Size(758, 596);
			this->picture_map->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picture_map->TabIndex = 0;
			this->picture_map->TabStop = false;
			this->picture_map->Click += gcnew System::EventHandler(this, &Form1::picture_map_Click);
			this->picture_map->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picture_map_MouseClick);
			this->picture_map->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picture_map_MouseDown);
			this->picture_map->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picture_map_MouseMove);
			this->picture_map->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picture_map_MouseUp);
			this->picture_map->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::picture_map_MouseWheel);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Enabled = false;
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->BeginItem, 
				this->EndItem, this->toolStripSeparator1, this->FindItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->ShowImageMargin = false;
			this->contextMenuStrip1->Size = System::Drawing::Size(134, 76);
			this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::contextMenuStrip1_Opening);
			// 
			// BeginItem
			// 
			this->BeginItem->Enabled = false;
			this->BeginItem->Name = L"BeginItem";
			this->BeginItem->Size = System::Drawing::Size(133, 22);
			this->BeginItem->Text = L"设置最短路起点";
			this->BeginItem->Click += gcnew System::EventHandler(this, &Form1::BeginItem_Click);
			// 
			// EndItem
			// 
			this->EndItem->Enabled = false;
			this->EndItem->Name = L"EndItem";
			this->EndItem->Size = System::Drawing::Size(133, 22);
			this->EndItem->Text = L"设置最短路终点";
			this->EndItem->Click += gcnew System::EventHandler(this, &Form1::EndItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(130, 6);
			// 
			// FindItem
			// 
			this->FindItem->Enabled = false;
			this->FindItem->Name = L"FindItem";
			this->FindItem->Size = System::Drawing::Size(133, 22);
			this->FindItem->Text = L"开始寻找";
			this->FindItem->Click += gcnew System::EventHandler(this, &Form1::FindItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 618);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Test";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(799, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Height:";
			// 
			// m_width
			// 
			this->m_width->Location = System::Drawing::Point(864, 27);
			this->m_width->MaxLength = 5;
			this->m_width->Name = L"m_width";
			this->m_width->Size = System::Drawing::Size(96, 21);
			this->m_width->TabIndex = 3;
			this->m_width->Text = L"1000";
			this->m_width->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(806, 67);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(153, 30);
			this->button2->TabIndex = 4;
			this->button2->Text = L"读取文件";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button3->Location = System::Drawing::Point(806, 112);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(153, 30);
			this->button3->TabIndex = 5;
			this->button3->Text = L"描绘地图";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button4->Location = System::Drawing::Point(806, 157);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(153, 29);
			this->button4->TabIndex = 6;
			this->button4->Text = L"保存图片";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"osm file(*.osm)|*.osm";
			this->openFileDialog1->RestoreDirectory = true;
			this->openFileDialog1->Title = L"打开";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"jpg";
			this->saveFileDialog1->Filter = L"Bitmap file(*.bmp)|*.bmp";
			this->saveFileDialog1->RestoreDirectory = true;
			this->saveFileDialog1->Title = L"导出图片";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->checkBox1->Location = System::Drawing::Point(6, 20);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(99, 21);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"显示道路名称";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(801, 198);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(168, 79);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"地图设置";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->checkBox2->Location = System::Drawing::Point(6, 47);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(99, 21);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"显示道路类型";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->PathSelect2);
			this->groupBox2->Controls->Add(this->PathSelect1);
			this->groupBox2->Location = System::Drawing::Point(801, 287);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(166, 76);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"最短路设置";
			// 
			// PathSelect1
			// 
			this->PathSelect1->AutoSize = true;
			this->PathSelect1->Checked = true;
			this->PathSelect1->Location = System::Drawing::Point(6, 23);
			this->PathSelect1->Name = L"PathSelect1";
			this->PathSelect1->Size = System::Drawing::Size(71, 16);
			this->PathSelect1->TabIndex = 0;
			this->PathSelect1->TabStop = true;
			this->PathSelect1->Text = L"快速查找";
			this->PathSelect1->UseVisualStyleBackColor = true;
			// 
			// PathSelect2
			// 
			this->PathSelect2->AutoSize = true;
			this->PathSelect2->Location = System::Drawing::Point(6, 48);
			this->PathSelect2->Name = L"PathSelect2";
			this->PathSelect2->Size = System::Drawing::Size(71, 16);
			this->PathSelect2->TabIndex = 1;
			this->PathSelect2->Text = L"传统查找";
			this->PathSelect2->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(993, 616);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->m_width);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MapTool";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picture_map))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 //程序默认初始化设置
				 map = NULL;
				 pic_mouse = false;
				 default_pic_width = picture_map->Width;
				 default_pic_height = picture_map->Height;
				 ShowName = false;
				 ShowFlag = false;
				 set_begin = set_end = false;
				 //创建画笔系列
				 motorway_pen = gcnew System::Drawing::Pen(System::Drawing::Color::SteelBlue,4);
				 motorway_link_pen = gcnew System::Drawing::Pen(System::Drawing::Color::LightSeaGreen,3);
				 trunk_pen = gcnew System::Drawing::Pen(System::Drawing::Color::LightGreen,3);
				 primary_pen = gcnew System::Drawing::Pen(System::Drawing::Color::SaddleBrown,3);
				 secondary_pen = gcnew System::Drawing::Pen(System::Drawing::Color::HotPink,3);
				 tertiary_pen = gcnew System::Drawing::Pen(System::Drawing::Color::Gold,3);
				 unclassified_pen = gcnew System::Drawing::Pen(System::Drawing::Color::Gray,2);
				 service_pen = gcnew System::Drawing::Pen(System::Drawing::Color::Indigo,2);
				 track_pen = gcnew System::Drawing::Pen(System::Drawing::Color::OrangeRed,2);
				 footway_pen = gcnew System::Drawing::Pen(System::Drawing::Color::OrangeRed,2);
				 footway_pen->DashStyle = System::Drawing::Drawing2D::DashStyle::DashDot;
				 waterway_pen = gcnew System::Drawing::Pen(System::Drawing::Color::DeepSkyBlue,4);
				 other_pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black,1);
				 undefined_pen = gcnew System::Drawing::Pen(System::Drawing::Color::DarkGray,1);

				 shortpath_pen = gcnew System::Drawing::Pen(System::Drawing::Color::CornflowerBlue,5);

			 }
	private: System::Void picture_map_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if(!bmp) return;
				 int top=0,left=0;
				 int _w = picture_map->Width;
				 int x ;
				 int y ;
				 // x y 用来计算pictureBox的需要移动的距离来保证图片焦点缩放效果， e->X 返回当前鼠标指向的点在当前picture_map里的坐标
				 if(e->Delta>0)
				 {
					 if(picture_map->Height > bmp->Height * 10 || picture_map->Height * 1.2 > 1<<16-1 || picture_map->Width * 1.2 > 1<<16-1) return;
					 picture_map->Height *=1.2;
					 picture_map->Width  *=1.2;
					 x = e->X - 1.2 * e->X;
					 y = e->Y - 1.2 * e->Y;
				 }else if(e->Delta<0)
				 {
					 if(picture_map->Height / 1.2 < 500) return;
					 picture_map->Height /= 1.2;
					 picture_map->Width /= 1.2;
					 x = e->X - e->X / 1.2;
					 y = e->Y - e->Y / 1.2;
				 }
				 if(picture_map->Top + y> 3) picture_map->Top = 3;
				 else if(picture_map->Top + y + picture_map->Height < panel1->Height) picture_map->Top = panel1->Height - picture_map->Height;
				 else picture_map->Top +=y;
				 if(picture_map->Left + x> 3) picture_map->Left = 3; 
				 else if(picture_map->Left + x + picture_map->Width < panel1->Width) picture_map->Left = panel1->Width - picture_map->Width;
				 else picture_map->Left +=x;
				 
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
			 
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ filename;
				 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 filename = openFileDialog1->FileName;
				 else return;
				 using namespace System::Runtime::InteropServices;
				 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(filename); //String 转 char*
				 if(map) delete map;
				 map = new Mymap();
				 if(map->LoadMapFile(str))
				 {
					 button3->Enabled = true;
					 MessageBox::Show("文件加载成功！");
					 if(path) delete path;
					 path = new ShortestPath();
					 path->InitPath(map);
				 }else
				 {
					 button3->Enabled = false;
					 MessageBox::Show("加载文件失败！");
					 return;
				 }
				 contextMenuStrip1->Enabled = false;
			 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 int width,height;
			 bool isok;
			 isok = int::TryParse(m_width->Text,width);
			 if(!isok || width <=0 || width>10000)
			 {
				 MessageBox::Show("输入非法或超出范围！");
				 return;
			 }
			 button4->Enabled = true;
			 contextMenuStrip1->Enabled = true;
			 BeginItem->Enabled  =true; EndItem->Enabled = true;
			 height = width * (map->maxlon - map->minlon)/(map->maxlat - map->minlat); //根据实际图的范围得到height值
			 myPen = other_pen; //选择默认画笔
			 if(bmp) delete bmp;
			 bmp = gcnew System::Drawing::Bitmap(height,width); //新建位图
			 //画地图
			 Graphics^g = Graphics::FromImage(bmp);
			 myFont = gcnew System::Drawing::Font(L"宋体",9); //创建字体
		     bru1 = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black); //创建画刷
			 way * w = map->GetWay();
			 Node * n1,*n2;
			 float x1,x2,y1,y2;
			 Link * lk;
			 int cur_count;
			 while(w)
			 {
				 lk = w->lk;
				 n1 = lk->nd;
				 lk = lk->next;
				 cur_count = 0;
				 if(ShowFlag) myPen = SelectPen(w->flag);
				 while(lk)
				 {
					 n2 = lk->nd;
					 x1 = width - (n1->lat - map->minlat) / (map->maxlat - map->minlat) * width;
					 y1 = (n1->lon - map->minlon) / (map->maxlon - map->minlon) * height;
					 x2 = width - (n2->lat - map->minlat) / (map->maxlat - map->minlat) * width;
					 y2 = (n2->lon - map->minlon) / (map->maxlon - map->minlon) * height;
					 g->DrawLine(myPen,y1,x1,y2,x2);
					 if(ShowName && w->name && ++cur_count == w->size ) //取路线中点画路线名
					 {  
						 String^ str1= System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)w->name);
						 g->DrawString(str1,myFont,bru1,y2,x2);
						 delete str1;
					 }
					 n1 = n2; n2 = NULL;
					 lk = lk->next;
				 }
				 w = w->next;
			 }
			 picture_map->Top = 3;
			 picture_map->Left = 3;
			 picture_map->Width  = default_pic_width;
			 picture_map->Height = default_pic_height;
			 picture_map->Image = bmp; 
			 delete g;
			 delete myFont;
			 delete bru1;

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(bmp)
			 {
				 String^ filename;
				 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 filename = saveFileDialog1->FileName;
					 if(filename->Length <= 0)
					 {
						 MessageBox::Show("文件名不能为空！");
						 return;
					 }
					 bmp->Save(filename);
					 MessageBox::Show("保存成功！");

				 }
			 }
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void picture_map_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->picture_map->Focus();
		 }
private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
		 }
private: System::Void picture_map_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void picture_map_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(pic_mouse)
			 {
				 if(picture_map->Top + e->Y - curY > 3) picture_map->Top = 3;
				 else if(picture_map->Top + e->Y - curY + picture_map->Height < panel1->Height) picture_map->Top = picture_map->Top;
					else picture_map->Top += e->Y - curY;
				 if(picture_map->Left + e->X - curX > 3) picture_map->Left = 3; 
				 else if(picture_map->Left + e->X - curX + picture_map->Width < panel1->Width) picture_map->Left = picture_map->Left;
					else picture_map->Left += e->X - curX;
			 }
		 }
private: System::Void picture_map_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(e->Button == System::Windows::Forms::MouseButtons::Left && bmp)
			 {
				 curX = e->X;
				 curY = e->Y;
				 pic_mouse  = true;
			 }else if(e->Button == System::Windows::Forms::MouseButtons::Right && bmp)
			 {
				 curX = e->X;
				 curY = e->Y;
			 }
		 }
private: System::Void picture_map_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(e->Button == System::Windows::Forms::MouseButtons::Left)
			 {
				 pic_mouse  = false;
			 }
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(checkBox1->Checked)
				 ShowName = true;
			 else ShowName = false;
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(checkBox2->Checked)
				 ShowFlag = true;
			 else ShowFlag = false;
		 }
private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void BeginItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(set_begin)
			 {
				 set_begin = false;
				 BeginItem->Text = L"设置最短路起点";
				 FindItem->Enabled = false;
			 }else
			 {
				 set_begin = true;
				 if(bmp->Width>=bmp->Height)
				 {
					double yy = picture_map->Height-(double)picture_map->Width/bmp->Width*bmp->Height;
					curY = curY - yy/2;
					begin_lat = (double)(picture_map->Height-yy-curY)/(picture_map->Height-yy) * (map->maxlat - map->minlat) + map->minlat;
					begin_lon = (double)curX/picture_map->Width * (map->maxlon - map->minlon) + map->minlon;
				 }else
				 {
					 double yy = picture_map->Width - (double)picture_map->Height/bmp->Height*bmp->Width;
					 curX = curX - yy/2;
					 begin_lat = (double)(picture_map->Height-curY)/(picture_map->Height) * (map->maxlat - map->minlat) + map->minlat;
					 begin_lon = (double)curX/(picture_map->Width-yy) * (map->maxlon - map->minlon) + map->minlon;
				 }
				 BeginItem->Text = L"重置最短路起点";
				 if(set_begin && set_end) FindItem->Enabled = true;
			 }
		 }
private: System::Void EndItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(set_end)
			 {
				 set_end = false;
				 EndItem->Text = L"设置最短路终点";
				 FindItem->Enabled = false;
			 }else
			 {
				 set_end = true;
				 if(bmp->Width>=bmp->Height)
				 {
					double yy = picture_map->Height-(double)picture_map->Width/bmp->Width*bmp->Height;
					curY = curY - yy/2;
					end_lat = (double)(picture_map->Height-yy-curY)/(picture_map->Height-yy) * (map->maxlat - map->minlat) + map->minlat;
					end_lon = (double)curX/picture_map->Width * (map->maxlon - map->minlon) + map->minlon;
				 }else
				 {
					 double yy = picture_map->Width - (double)picture_map->Height/bmp->Height*bmp->Width;
					 curX = curX - yy/2;
					 end_lat = (double)(picture_map->Height-curY)/(picture_map->Height) * (map->maxlat - map->minlat) + map->minlat;
					 end_lon = (double)curX/(picture_map->Width-yy) * (map->maxlon - map->minlon) + map->minlon;
				 }

				 EndItem->Text = L"重置最短路终点";
				 if(set_begin && set_end) FindItem->Enabled = true;
			 }
		 }
private: System::Void FindItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Node* begin_node = path->SetBeginPath(begin_lat,begin_lon);
			 Node* end_node = path->SetEndPath(end_lat,end_lon);
			 Prenode * pre;
			 System::Diagnostics::Stopwatch st; //用于记录运行时间
			 st.Start();
			 if(PathSelect1->Checked)
				pre = path->FindShortPath2();
			 else pre = path->FindShortPath();
			 st.Stop();
			 TimeSpan timespan = st.Elapsed;
			 //MessageBox::Show(timespan.TotalMilliseconds.ToString()+"ms"); 显示最短路运行时间
			 Graphics^g = Graphics::FromImage(bmp);
			 int i = end_node->my_id;
			 float x1,x2,y1,y2;
			 int width = bmp->Height; int height = bmp->Width;
			 Node*n1,*n2;
			 n1 = end_node; i = end_node->my_id;
			 x1 = width - (n1->lat - map->minlat) / (map->maxlat - map->minlat) * width;
			 y1 = (n1->lon - map->minlon) / (map->maxlon - map->minlon) * height;
			 g->FillEllipse(System::Drawing::Brushes::CornflowerBlue,(int)y1,(int)x1,10,10);
			 while(pre[i].id)
			 {
				 n2 = pre[i].node;
				 x1 = width - (n1->lat - map->minlat) / (map->maxlat - map->minlat) * width;
				 y1 = (n1->lon - map->minlon) / (map->maxlon - map->minlon) * height;
				 x2 = width - (n2->lat - map->minlat) / (map->maxlat - map->minlat) * width;
				 y2 = (n2->lon - map->minlon) / (map->maxlon - map->minlon) * height;
				 g->DrawLine(shortpath_pen,y1,x1,y2,x2);
				 n1 = n2;
				 i = pre[i].id;
			 }
			 g->FillEllipse(System::Drawing::Brushes::CornflowerBlue,(int)y2,(int)x2,10,10);
			 picture_map->Image = bmp; 
			 delete g;
		 }
};
}

