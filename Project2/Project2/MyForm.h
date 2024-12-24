
#pragma once
#include "modules.h"
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>  // For converting System::String to std::string
#include "powerc.h"
#include "periodic2.h"
#include "alarm2.h"
#include "filteration.h"
#include "powerfactor.h"
#include "cost.h"
#include <fstream>

home_appliance DeviceOne, DeviceTwo, DeviceThree, DeviceFour, DeviceFive;
vector<signal> waveform, waveform2, waveform3, waveform4, waveform5;
powercalculator power;
energycalc energy_c1, energy_c2, energy_c3, energy_c4, energy_c5;
double energyD1, energyD2, energyD3, energyD4, energyD5, energyTotal;
double powerD1 = 0.0;
double powerD2 = 0.0;
double powerD3 = 0.0; 
double powerD4 = 0.0; 
double powerD5 = 0.0;
double powerTotal;
vector<double> period1, period2, period3, period4, period5;
double load1_powerfactor, load2_powerfactor, load3_powerfactor, load4_powerfactor, load5_powerfactor;
double total_bill;
double X,TSampling;
bool click_sampling = 0;

namespace MyForm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ SmartMeter;
    private: System::Windows::Forms::Label^ ChooseLabel1;

    private: System::Windows::Forms::Button^ LoadBTN;
    private: System::Windows::Forms::Button^ SaveBTN;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
    private: System::Windows::Forms::TextBox^ TB_MaxVoltage1;
    private: System::Windows::Forms::TextBox^ TB_MaxCurrent1;



    private: System::Windows::Forms::Label^ ChooseLabel2;
    private: System::Windows::Forms::Label^ ChooseLabel3;
    private: System::Windows::Forms::Label^ ChooseLabel4;



    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Label^ MaxVoltLabel1;
    private: System::Windows::Forms::Label^ MaxCurrentLabel1;
    private: System::Windows::Forms::Label^ DevicePowerLabel1;
    private: System::Windows::Forms::Label^ Power1;
    private: System::Windows::Forms::Label^ DeviceEnergy1;





    private: System::Windows::Forms::Label^ Energy1;

    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ PowerTotal;

    private: System::Windows::Forms::Label^ DevicesEnergy;

    private: System::Windows::Forms::Label^ EnergyTotal;

    private: System::Windows::Forms::Label^ MaxVoltLabel2;
    private: System::Windows::Forms::Label^ MaxVoltLabel3;
    private: System::Windows::Forms::Label^ MaxVoltLabel4;
    private: System::Windows::Forms::Label^ MaxCurrentLabel2;
    private: System::Windows::Forms::Label^ MaxCurrentLabel3;
    private: System::Windows::Forms::Label^ MaxCurrentLabel4;
    private: System::Windows::Forms::Label^ DevicePowerLabel2;
    private: System::Windows::Forms::Label^ DevicePowerLabel3;
    private: System::Windows::Forms::Label^ DevicePowerLabel4;
    private: System::Windows::Forms::Label^ Power2;
    private: System::Windows::Forms::Label^ Power3;
    private: System::Windows::Forms::Label^ Power4;
    private: System::Windows::Forms::Label^ Energy2;
    private: System::Windows::Forms::Label^ Energy3;
    private: System::Windows::Forms::Label^ Energy4;
    private: System::Windows::Forms::Label^ DeviceEnergy2;
    private: System::Windows::Forms::Label^ DeviceEnergy3;
    private: System::Windows::Forms::Label^ DeviceEnergy4;
    private: System::Windows::Forms::TextBox^ TB_MaxVoltage2;
    private: System::Windows::Forms::TextBox^ TB_MaxCurrent2;




















    private: System::Windows::Forms::TextBox^ TB_MaxVoltage3;
    private: System::Windows::Forms::TextBox^ TB_MaxCurrent3;


    private: System::Windows::Forms::TextBox^ TB_MaxVoltage4;
    private: System::Windows::Forms::TextBox^ TB_MaxCurrent4;


    private: System::Windows::Forms::Label^ BillLabel;

    private: System::Windows::Forms::Label^ Bill;

         


    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ Set_M_V1;
    private: System::Windows::Forms::Button^ Set_M_C1;


    private: System::Windows::Forms::Button^ Set_M_V2;
    private: System::Windows::Forms::Button^ Set_M_C2;


    private: System::Windows::Forms::Button^ Set_M_V3;
    private: System::Windows::Forms::Button^ Set_M_C3;


    private: System::Windows::Forms::Button^ Set_M_V4;
    private: System::Windows::Forms::Button^ Set_M_C4;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog3;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog4;
    private: System::Windows::Forms::Button^ Calculate1;
    private: System::Windows::Forms::Button^ Calculate2;
private: System::Windows::Forms::Label^ PF1;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label_value_PF1;
private: System::Windows::Forms::Label^ label_value_PF2;
private: System::Windows::Forms::Label^ label_value_PF3;
private: System::Windows::Forms::Label^ label_value_PF4;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::SaveFileDialog^ saveFileDialog2;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::TextBox^ TB_MaxVoltage5;
private: System::Windows::Forms::TextBox^ TB_MaxCurrent5;


private: System::Windows::Forms::Button^ Set_M_V5;
private: System::Windows::Forms::Button^ Set_M_C5;


private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::TextBox^ Tsampling_TB;
private: System::Windows::Forms::Label^ Power5;
private: System::Windows::Forms::Label^ Energy5;
private: System::Windows::Forms::Label^ label_value_PF5;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog5;
















    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
               this->SmartMeter = (gcnew System::Windows::Forms::Label());
               this->ChooseLabel1 = (gcnew System::Windows::Forms::Label());
               this->LoadBTN = (gcnew System::Windows::Forms::Button());
               this->SaveBTN = (gcnew System::Windows::Forms::Button());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->TB_MaxVoltage1 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxCurrent1 = (gcnew System::Windows::Forms::TextBox());
               this->ChooseLabel2 = (gcnew System::Windows::Forms::Label());
               this->ChooseLabel3 = (gcnew System::Windows::Forms::Label());
               this->ChooseLabel4 = (gcnew System::Windows::Forms::Label());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->button3 = (gcnew System::Windows::Forms::Button());
               this->MaxVoltLabel1 = (gcnew System::Windows::Forms::Label());
               this->MaxCurrentLabel1 = (gcnew System::Windows::Forms::Label());
               this->DevicePowerLabel1 = (gcnew System::Windows::Forms::Label());
               this->Power1 = (gcnew System::Windows::Forms::Label());
               this->DeviceEnergy1 = (gcnew System::Windows::Forms::Label());
               this->Energy1 = (gcnew System::Windows::Forms::Label());
               this->label11 = (gcnew System::Windows::Forms::Label());
               this->PowerTotal = (gcnew System::Windows::Forms::Label());
               this->DevicesEnergy = (gcnew System::Windows::Forms::Label());
               this->EnergyTotal = (gcnew System::Windows::Forms::Label());
               this->MaxVoltLabel2 = (gcnew System::Windows::Forms::Label());
               this->MaxVoltLabel3 = (gcnew System::Windows::Forms::Label());
               this->MaxVoltLabel4 = (gcnew System::Windows::Forms::Label());
               this->MaxCurrentLabel2 = (gcnew System::Windows::Forms::Label());
               this->MaxCurrentLabel3 = (gcnew System::Windows::Forms::Label());
               this->MaxCurrentLabel4 = (gcnew System::Windows::Forms::Label());
               this->DevicePowerLabel2 = (gcnew System::Windows::Forms::Label());
               this->DevicePowerLabel3 = (gcnew System::Windows::Forms::Label());
               this->DevicePowerLabel4 = (gcnew System::Windows::Forms::Label());
               this->Power2 = (gcnew System::Windows::Forms::Label());
               this->Power3 = (gcnew System::Windows::Forms::Label());
               this->Power4 = (gcnew System::Windows::Forms::Label());
               this->Energy2 = (gcnew System::Windows::Forms::Label());
               this->Energy3 = (gcnew System::Windows::Forms::Label());
               this->Energy4 = (gcnew System::Windows::Forms::Label());
               this->DeviceEnergy2 = (gcnew System::Windows::Forms::Label());
               this->DeviceEnergy3 = (gcnew System::Windows::Forms::Label());
               this->DeviceEnergy4 = (gcnew System::Windows::Forms::Label());
               this->TB_MaxVoltage2 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxCurrent2 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxVoltage3 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxCurrent3 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxVoltage4 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxCurrent4 = (gcnew System::Windows::Forms::TextBox());
               this->BillLabel = (gcnew System::Windows::Forms::Label());
               this->Bill = (gcnew System::Windows::Forms::Label());
               this->button4 = (gcnew System::Windows::Forms::Button());
               this->Set_M_V1 = (gcnew System::Windows::Forms::Button());
               this->Set_M_C1 = (gcnew System::Windows::Forms::Button());
               this->Set_M_V2 = (gcnew System::Windows::Forms::Button());
               this->Set_M_C2 = (gcnew System::Windows::Forms::Button());
               this->Set_M_V3 = (gcnew System::Windows::Forms::Button());
               this->Set_M_C3 = (gcnew System::Windows::Forms::Button());
               this->Set_M_V4 = (gcnew System::Windows::Forms::Button());
               this->Set_M_C4 = (gcnew System::Windows::Forms::Button());
               this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->openFileDialog4 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->Calculate1 = (gcnew System::Windows::Forms::Button());
               this->Calculate2 = (gcnew System::Windows::Forms::Button());
               this->PF1 = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label_value_PF1 = (gcnew System::Windows::Forms::Label());
               this->label_value_PF2 = (gcnew System::Windows::Forms::Label());
               this->label_value_PF3 = (gcnew System::Windows::Forms::Label());
               this->label_value_PF4 = (gcnew System::Windows::Forms::Label());
               this->button5 = (gcnew System::Windows::Forms::Button());
               this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->label9 = (gcnew System::Windows::Forms::Label());
               this->label10 = (gcnew System::Windows::Forms::Label());
               this->label12 = (gcnew System::Windows::Forms::Label());
               this->label13 = (gcnew System::Windows::Forms::Label());
               this->label14 = (gcnew System::Windows::Forms::Label());
               this->label15 = (gcnew System::Windows::Forms::Label());
               this->label16 = (gcnew System::Windows::Forms::Label());
               this->label17 = (gcnew System::Windows::Forms::Label());
               this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
               this->label18 = (gcnew System::Windows::Forms::Label());
               this->button6 = (gcnew System::Windows::Forms::Button());
               this->label19 = (gcnew System::Windows::Forms::Label());
               this->label20 = (gcnew System::Windows::Forms::Label());
               this->TB_MaxVoltage5 = (gcnew System::Windows::Forms::TextBox());
               this->TB_MaxCurrent5 = (gcnew System::Windows::Forms::TextBox());
               this->Set_M_V5 = (gcnew System::Windows::Forms::Button());
               this->Set_M_C5 = (gcnew System::Windows::Forms::Button());
               this->label21 = (gcnew System::Windows::Forms::Label());
               this->label22 = (gcnew System::Windows::Forms::Label());
               this->label23 = (gcnew System::Windows::Forms::Label());
               this->label24 = (gcnew System::Windows::Forms::Label());
               this->label25 = (gcnew System::Windows::Forms::Label());
               this->label26 = (gcnew System::Windows::Forms::Label());
               this->label27 = (gcnew System::Windows::Forms::Label());
               this->label28 = (gcnew System::Windows::Forms::Label());
               this->button9 = (gcnew System::Windows::Forms::Button());
               this->Tsampling_TB = (gcnew System::Windows::Forms::TextBox());
               this->Power5 = (gcnew System::Windows::Forms::Label());
               this->Energy5 = (gcnew System::Windows::Forms::Label());
               this->label_value_PF5 = (gcnew System::Windows::Forms::Label());
               this->openFileDialog5 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->SuspendLayout();
               // 
               // SmartMeter
               // 
               this->SmartMeter->AutoSize = true;
               this->SmartMeter->BackColor = System::Drawing::SystemColors::InactiveBorder;
               this->SmartMeter->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->SmartMeter->Location = System::Drawing::Point(836, 9);
               this->SmartMeter->Name = L"SmartMeter";
               this->SmartMeter->Size = System::Drawing::Size(116, 28);
               this->SmartMeter->TabIndex = 0;
               this->SmartMeter->Text = L"Smart Meter";
               // 
               // ChooseLabel1
               // 
               this->ChooseLabel1->AutoSize = true;
               this->ChooseLabel1->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->ChooseLabel1->Location = System::Drawing::Point(66, 101);
               this->ChooseLabel1->Name = L"ChooseLabel1";
               this->ChooseLabel1->Size = System::Drawing::Size(185, 28);
               this->ChooseLabel1->TabIndex = 1;
               this->ChooseLabel1->Text = L"Choose Load file:";
               // 
               // LoadBTN
               // 
               this->LoadBTN->Location = System::Drawing::Point(84, 132);
               this->LoadBTN->Name = L"LoadBTN";
               this->LoadBTN->Size = System::Drawing::Size(137, 34);
               this->LoadBTN->TabIndex = 2;
               this->LoadBTN->Text = L"Browse";
               this->LoadBTN->UseVisualStyleBackColor = true;
               this->LoadBTN->Click += gcnew System::EventHandler(this, &Form1::LoadBTN_Click);
               // 
               // SaveBTN
               // 
               this->SaveBTN->Location = System::Drawing::Point(1048, 600);
               this->SaveBTN->Name = L"SaveBTN";
               this->SaveBTN->Size = System::Drawing::Size(137, 34);
               this->SaveBTN->TabIndex = 3;
               this->SaveBTN->Text = L"Save";
               this->SaveBTN->UseVisualStyleBackColor = true;
               this->SaveBTN->Click += gcnew System::EventHandler(this, &Form1::SaveBTN_Click);
               // 
               // openFileDialog1
               // 
               this->openFileDialog1->FileName = L"openFileDialog1";
               // 
               // TB_MaxVoltage1
               // 
               this->TB_MaxVoltage1->Location = System::Drawing::Point(144, 205);
               this->TB_MaxVoltage1->Name = L"TB_MaxVoltage1";
               this->TB_MaxVoltage1->Size = System::Drawing::Size(58, 22);
               this->TB_MaxVoltage1->TabIndex = 4;
               this->TB_MaxVoltage1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
               // 
               // TB_MaxCurrent1
               // 
               this->TB_MaxCurrent1->Location = System::Drawing::Point(144, 254);
               this->TB_MaxCurrent1->Name = L"TB_MaxCurrent1";
               this->TB_MaxCurrent1->Size = System::Drawing::Size(58, 22);
               this->TB_MaxCurrent1->TabIndex = 5;
               // 
               // ChooseLabel2
               // 
               this->ChooseLabel2->AutoSize = true;
               this->ChooseLabel2->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->ChooseLabel2->Location = System::Drawing::Point(370, 101);
               this->ChooseLabel2->Name = L"ChooseLabel2";
               this->ChooseLabel2->Size = System::Drawing::Size(185, 28);
               this->ChooseLabel2->TabIndex = 6;
               this->ChooseLabel2->Text = L"Choose Load file:";
               // 
               // ChooseLabel3
               // 
               this->ChooseLabel3->AutoSize = true;
               this->ChooseLabel3->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->ChooseLabel3->Location = System::Drawing::Point(645, 101);
               this->ChooseLabel3->Name = L"ChooseLabel3";
               this->ChooseLabel3->Size = System::Drawing::Size(185, 28);
               this->ChooseLabel3->TabIndex = 7;
               this->ChooseLabel3->Text = L"Choose Load file:";
               // 
               // ChooseLabel4
               // 
               this->ChooseLabel4->AutoSize = true;
               this->ChooseLabel4->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->ChooseLabel4->Location = System::Drawing::Point(970, 101);
               this->ChooseLabel4->Name = L"ChooseLabel4";
               this->ChooseLabel4->Size = System::Drawing::Size(185, 28);
               this->ChooseLabel4->TabIndex = 8;
               this->ChooseLabel4->Text = L"Choose Load file:";
               // 
               // button1
               // 
               this->button1->Location = System::Drawing::Point(389, 132);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(137, 34);
               this->button1->TabIndex = 9;
               this->button1->Text = L"Browse";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
               // 
               // button2
               // 
               this->button2->Location = System::Drawing::Point(659, 132);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(137, 34);
               this->button2->TabIndex = 10;
               this->button2->Text = L"Browse";
               this->button2->UseVisualStyleBackColor = true;
               this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
               // 
               // button3
               // 
               this->button3->Location = System::Drawing::Point(992, 132);
               this->button3->Name = L"button3";
               this->button3->Size = System::Drawing::Size(137, 34);
               this->button3->TabIndex = 11;
               this->button3->Text = L"Browse";
               this->button3->UseVisualStyleBackColor = true;
               this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
               // 
               // MaxVoltLabel1
               // 
               this->MaxVoltLabel1->AutoSize = true;
               this->MaxVoltLabel1->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxVoltLabel1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxVoltLabel1->ForeColor = System::Drawing::Color::Red;
               this->MaxVoltLabel1->Location = System::Drawing::Point(12, 204);
               this->MaxVoltLabel1->Name = L"MaxVoltLabel1";
               this->MaxVoltLabel1->Size = System::Drawing::Size(111, 21);
               this->MaxVoltLabel1->TabIndex = 12;
               this->MaxVoltLabel1->Text = L"Max Voltage:";
               this->MaxVoltLabel1->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
               // 
               // MaxCurrentLabel1
               // 
               this->MaxCurrentLabel1->AutoSize = true;
               this->MaxCurrentLabel1->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxCurrentLabel1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxCurrentLabel1->ForeColor = System::Drawing::Color::Red;
               this->MaxCurrentLabel1->Location = System::Drawing::Point(10, 254);
               this->MaxCurrentLabel1->Name = L"MaxCurrentLabel1";
               this->MaxCurrentLabel1->Size = System::Drawing::Size(110, 21);
               this->MaxCurrentLabel1->TabIndex = 13;
               this->MaxCurrentLabel1->Text = L"Max Current:";
               // 
               // DevicePowerLabel1
               // 
               this->DevicePowerLabel1->AutoSize = true;
               this->DevicePowerLabel1->BackColor = System::Drawing::SystemColors::InfoText;
               this->DevicePowerLabel1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DevicePowerLabel1->ForeColor = System::Drawing::Color::Chocolate;
               this->DevicePowerLabel1->Location = System::Drawing::Point(10, 309);
               this->DevicePowerLabel1->Name = L"DevicePowerLabel1";
               this->DevicePowerLabel1->Size = System::Drawing::Size(117, 21);
               this->DevicePowerLabel1->TabIndex = 14;
               this->DevicePowerLabel1->Text = L"Device Power:";
               this->DevicePowerLabel1->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
               // 
               // Power1
               // 
               this->Power1->AutoSize = true;
               this->Power1->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Power1->Location = System::Drawing::Point(166, 302);
               this->Power1->Name = L"Power1";
               this->Power1->Size = System::Drawing::Size(0, 28);
               this->Power1->TabIndex = 15;
               // 
               // DeviceEnergy1
               // 
               this->DeviceEnergy1->AutoSize = true;
               this->DeviceEnergy1->BackColor = System::Drawing::SystemColors::InfoText;
               this->DeviceEnergy1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DeviceEnergy1->ForeColor = System::Drawing::Color::Chocolate;
               this->DeviceEnergy1->Location = System::Drawing::Point(10, 367);
               this->DeviceEnergy1->Name = L"DeviceEnergy1";
               this->DeviceEnergy1->Size = System::Drawing::Size(124, 21);
               this->DeviceEnergy1->TabIndex = 16;
               this->DeviceEnergy1->Text = L"Device Energy:";
               // 
               // Energy1
               // 
               this->Energy1->AutoSize = true;
               this->Energy1->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Energy1->Location = System::Drawing::Point(154, 360);
               this->Energy1->Name = L"Energy1";
               this->Energy1->Size = System::Drawing::Size(0, 28);
               this->Energy1->TabIndex = 17;
               // 
               // label11
               // 
               this->label11->AutoSize = true;
               this->label11->BackColor = System::Drawing::SystemColors::HotTrack;
               this->label11->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label11->ForeColor = System::Drawing::Color::Yellow;
               this->label11->Location = System::Drawing::Point(330, 517);
               this->label11->Name = L"label11";
               this->label11->Size = System::Drawing::Size(142, 28);
               this->label11->TabIndex = 18;
               this->label11->Text = L"Total power:";
               // 
               // PowerTotal
               // 
               this->PowerTotal->AutoSize = true;
               this->PowerTotal->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->PowerTotal->Location = System::Drawing::Point(534, 517);
               this->PowerTotal->Name = L"PowerTotal";
               this->PowerTotal->Size = System::Drawing::Size(0, 28);
               this->PowerTotal->TabIndex = 19;
               // 
               // DevicesEnergy
               // 
               this->DevicesEnergy->AutoSize = true;
               this->DevicesEnergy->BackColor = System::Drawing::SystemColors::HotTrack;
               this->DevicesEnergy->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DevicesEnergy->ForeColor = System::Drawing::Color::Yellow;
               this->DevicesEnergy->Location = System::Drawing::Point(330, 566);
               this->DevicesEnergy->Name = L"DevicesEnergy";
               this->DevicesEnergy->Size = System::Drawing::Size(152, 28);
               this->DevicesEnergy->TabIndex = 20;
               this->DevicesEnergy->Text = L"Total Energy:";
               // 
               // EnergyTotal
               // 
               this->EnergyTotal->AutoSize = true;
               this->EnergyTotal->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->EnergyTotal->Location = System::Drawing::Point(534, 566);
               this->EnergyTotal->Name = L"EnergyTotal";
               this->EnergyTotal->Size = System::Drawing::Size(0, 28);
               this->EnergyTotal->TabIndex = 21;
               // 
               // MaxVoltLabel2
               // 
               this->MaxVoltLabel2->AutoSize = true;
               this->MaxVoltLabel2->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxVoltLabel2->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxVoltLabel2->ForeColor = System::Drawing::Color::Red;
               this->MaxVoltLabel2->Location = System::Drawing::Point(306, 204);
               this->MaxVoltLabel2->Name = L"MaxVoltLabel2";
               this->MaxVoltLabel2->Size = System::Drawing::Size(111, 21);
               this->MaxVoltLabel2->TabIndex = 22;
               this->MaxVoltLabel2->Text = L"Max Voltage:";
               // 
               // MaxVoltLabel3
               // 
               this->MaxVoltLabel3->AutoSize = true;
               this->MaxVoltLabel3->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxVoltLabel3->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxVoltLabel3->ForeColor = System::Drawing::Color::Red;
               this->MaxVoltLabel3->Location = System::Drawing::Point(603, 204);
               this->MaxVoltLabel3->Name = L"MaxVoltLabel3";
               this->MaxVoltLabel3->Size = System::Drawing::Size(111, 21);
               this->MaxVoltLabel3->TabIndex = 23;
               this->MaxVoltLabel3->Text = L"Max Voltage:";
               // 
               // MaxVoltLabel4
               // 
               this->MaxVoltLabel4->AutoSize = true;
               this->MaxVoltLabel4->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxVoltLabel4->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxVoltLabel4->ForeColor = System::Drawing::Color::Red;
               this->MaxVoltLabel4->Location = System::Drawing::Point(918, 204);
               this->MaxVoltLabel4->Name = L"MaxVoltLabel4";
               this->MaxVoltLabel4->Size = System::Drawing::Size(111, 21);
               this->MaxVoltLabel4->TabIndex = 24;
               this->MaxVoltLabel4->Text = L"Max Voltage:";
               // 
               // MaxCurrentLabel2
               // 
               this->MaxCurrentLabel2->AutoSize = true;
               this->MaxCurrentLabel2->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxCurrentLabel2->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxCurrentLabel2->ForeColor = System::Drawing::Color::Red;
               this->MaxCurrentLabel2->Location = System::Drawing::Point(309, 255);
               this->MaxCurrentLabel2->Name = L"MaxCurrentLabel2";
               this->MaxCurrentLabel2->Size = System::Drawing::Size(110, 21);
               this->MaxCurrentLabel2->TabIndex = 25;
               this->MaxCurrentLabel2->Text = L"Max Current:";
               // 
               // MaxCurrentLabel3
               // 
               this->MaxCurrentLabel3->AutoSize = true;
               this->MaxCurrentLabel3->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxCurrentLabel3->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxCurrentLabel3->ForeColor = System::Drawing::Color::Red;
               this->MaxCurrentLabel3->Location = System::Drawing::Point(603, 253);
               this->MaxCurrentLabel3->Name = L"MaxCurrentLabel3";
               this->MaxCurrentLabel3->Size = System::Drawing::Size(110, 21);
               this->MaxCurrentLabel3->TabIndex = 26;
               this->MaxCurrentLabel3->Text = L"Max Current:";
               // 
               // MaxCurrentLabel4
               // 
               this->MaxCurrentLabel4->AutoSize = true;
               this->MaxCurrentLabel4->BackColor = System::Drawing::SystemColors::InfoText;
               this->MaxCurrentLabel4->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->MaxCurrentLabel4->ForeColor = System::Drawing::Color::Red;
               this->MaxCurrentLabel4->Location = System::Drawing::Point(918, 253);
               this->MaxCurrentLabel4->Name = L"MaxCurrentLabel4";
               this->MaxCurrentLabel4->Size = System::Drawing::Size(110, 21);
               this->MaxCurrentLabel4->TabIndex = 27;
               this->MaxCurrentLabel4->Text = L"Max Current:";
               // 
               // DevicePowerLabel2
               // 
               this->DevicePowerLabel2->AutoSize = true;
               this->DevicePowerLabel2->BackColor = System::Drawing::SystemColors::InfoText;
               this->DevicePowerLabel2->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DevicePowerLabel2->ForeColor = System::Drawing::Color::Chocolate;
               this->DevicePowerLabel2->Location = System::Drawing::Point(309, 309);
               this->DevicePowerLabel2->Name = L"DevicePowerLabel2";
               this->DevicePowerLabel2->Size = System::Drawing::Size(117, 21);
               this->DevicePowerLabel2->TabIndex = 28;
               this->DevicePowerLabel2->Text = L"Device Power:";
               // 
               // DevicePowerLabel3
               // 
               this->DevicePowerLabel3->AutoSize = true;
               this->DevicePowerLabel3->BackColor = System::Drawing::SystemColors::InfoText;
               this->DevicePowerLabel3->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DevicePowerLabel3->ForeColor = System::Drawing::Color::Chocolate;
               this->DevicePowerLabel3->Location = System::Drawing::Point(603, 309);
               this->DevicePowerLabel3->Name = L"DevicePowerLabel3";
               this->DevicePowerLabel3->Size = System::Drawing::Size(117, 21);
               this->DevicePowerLabel3->TabIndex = 29;
               this->DevicePowerLabel3->Text = L"Device Power:";
               // 
               // DevicePowerLabel4
               // 
               this->DevicePowerLabel4->AutoSize = true;
               this->DevicePowerLabel4->BackColor = System::Drawing::SystemColors::InfoText;
               this->DevicePowerLabel4->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DevicePowerLabel4->ForeColor = System::Drawing::Color::Chocolate;
               this->DevicePowerLabel4->Location = System::Drawing::Point(918, 309);
               this->DevicePowerLabel4->Name = L"DevicePowerLabel4";
               this->DevicePowerLabel4->Size = System::Drawing::Size(117, 21);
               this->DevicePowerLabel4->TabIndex = 30;
               this->DevicePowerLabel4->Text = L"Device Power:";
               // 
               // Power2
               // 
               this->Power2->AutoSize = true;
               this->Power2->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Power2->Location = System::Drawing::Point(450, 302);
               this->Power2->Name = L"Power2";
               this->Power2->Size = System::Drawing::Size(0, 28);
               this->Power2->TabIndex = 31;
               // 
               // Power3
               // 
               this->Power3->AutoSize = true;
               this->Power3->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Power3->Location = System::Drawing::Point(760, 304);
               this->Power3->Name = L"Power3";
               this->Power3->Size = System::Drawing::Size(0, 28);
               this->Power3->TabIndex = 32;
               // 
               // Power4
               // 
               this->Power4->AutoSize = true;
               this->Power4->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Power4->Location = System::Drawing::Point(1066, 302);
               this->Power4->Name = L"Power4";
               this->Power4->Size = System::Drawing::Size(0, 28);
               this->Power4->TabIndex = 33;
               // 
               // Energy2
               // 
               this->Energy2->AutoSize = true;
               this->Energy2->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Energy2->Location = System::Drawing::Point(450, 360);
               this->Energy2->Name = L"Energy2";
               this->Energy2->Size = System::Drawing::Size(0, 28);
               this->Energy2->TabIndex = 34;
               // 
               // Energy3
               // 
               this->Energy3->AutoSize = true;
               this->Energy3->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Energy3->Location = System::Drawing::Point(760, 367);
               this->Energy3->Name = L"Energy3";
               this->Energy3->Size = System::Drawing::Size(0, 28);
               this->Energy3->TabIndex = 35;
               // 
               // Energy4
               // 
               this->Energy4->AutoSize = true;
               this->Energy4->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Energy4->Location = System::Drawing::Point(1066, 353);
               this->Energy4->Name = L"Energy4";
               this->Energy4->Size = System::Drawing::Size(0, 28);
               this->Energy4->TabIndex = 36;
               // 
               // DeviceEnergy2
               // 
               this->DeviceEnergy2->AutoSize = true;
               this->DeviceEnergy2->BackColor = System::Drawing::SystemColors::InfoText;
               this->DeviceEnergy2->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DeviceEnergy2->ForeColor = System::Drawing::Color::Chocolate;
               this->DeviceEnergy2->Location = System::Drawing::Point(309, 367);
               this->DeviceEnergy2->Name = L"DeviceEnergy2";
               this->DeviceEnergy2->Size = System::Drawing::Size(124, 21);
               this->DeviceEnergy2->TabIndex = 37;
               this->DeviceEnergy2->Text = L"Device Energy:";
               // 
               // DeviceEnergy3
               // 
               this->DeviceEnergy3->AutoSize = true;
               this->DeviceEnergy3->BackColor = System::Drawing::SystemColors::InfoText;
               this->DeviceEnergy3->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DeviceEnergy3->ForeColor = System::Drawing::Color::Chocolate;
               this->DeviceEnergy3->Location = System::Drawing::Point(603, 367);
               this->DeviceEnergy3->Name = L"DeviceEnergy3";
               this->DeviceEnergy3->Size = System::Drawing::Size(124, 21);
               this->DeviceEnergy3->TabIndex = 38;
               this->DeviceEnergy3->Text = L"Device Energy:";
               // 
               // DeviceEnergy4
               // 
               this->DeviceEnergy4->AutoSize = true;
               this->DeviceEnergy4->BackColor = System::Drawing::SystemColors::InfoText;
               this->DeviceEnergy4->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->DeviceEnergy4->ForeColor = System::Drawing::Color::Chocolate;
               this->DeviceEnergy4->Location = System::Drawing::Point(918, 367);
               this->DeviceEnergy4->Name = L"DeviceEnergy4";
               this->DeviceEnergy4->Size = System::Drawing::Size(124, 21);
               this->DeviceEnergy4->TabIndex = 39;
               this->DeviceEnergy4->Text = L"Device Energy:";
               this->DeviceEnergy4->Click += gcnew System::EventHandler(this, &Form1::DeviceEnergy4_Click);
               // 
               // TB_MaxVoltage2
               // 
               this->TB_MaxVoltage2->Location = System::Drawing::Point(441, 204);
               this->TB_MaxVoltage2->Name = L"TB_MaxVoltage2";
               this->TB_MaxVoltage2->Size = System::Drawing::Size(58, 22);
               this->TB_MaxVoltage2->TabIndex = 40;
               // 
               // TB_MaxCurrent2
               // 
               this->TB_MaxCurrent2->Location = System::Drawing::Point(441, 254);
               this->TB_MaxCurrent2->Name = L"TB_MaxCurrent2";
               this->TB_MaxCurrent2->Size = System::Drawing::Size(58, 22);
               this->TB_MaxCurrent2->TabIndex = 41;
               // 
               // TB_MaxVoltage3
               // 
               this->TB_MaxVoltage3->Location = System::Drawing::Point(725, 206);
               this->TB_MaxVoltage3->Name = L"TB_MaxVoltage3";
               this->TB_MaxVoltage3->Size = System::Drawing::Size(56, 22);
               this->TB_MaxVoltage3->TabIndex = 42;
               // 
               // TB_MaxCurrent3
               // 
               this->TB_MaxCurrent3->Location = System::Drawing::Point(725, 252);
               this->TB_MaxCurrent3->Name = L"TB_MaxCurrent3";
               this->TB_MaxCurrent3->Size = System::Drawing::Size(54, 22);
               this->TB_MaxCurrent3->TabIndex = 43;
               // 
               // TB_MaxVoltage4
               // 
               this->TB_MaxVoltage4->Location = System::Drawing::Point(1048, 206);
               this->TB_MaxVoltage4->Name = L"TB_MaxVoltage4";
               this->TB_MaxVoltage4->Size = System::Drawing::Size(52, 22);
               this->TB_MaxVoltage4->TabIndex = 44;
               // 
               // TB_MaxCurrent4
               // 
               this->TB_MaxCurrent4->Location = System::Drawing::Point(1048, 253);
               this->TB_MaxCurrent4->Name = L"TB_MaxCurrent4";
               this->TB_MaxCurrent4->Size = System::Drawing::Size(52, 22);
               this->TB_MaxCurrent4->TabIndex = 45;
               // 
               // BillLabel
               // 
               this->BillLabel->AutoSize = true;
               this->BillLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->BillLabel->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->BillLabel->Location = System::Drawing::Point(918, 509);
               this->BillLabel->Name = L"BillLabel";
               this->BillLabel->Size = System::Drawing::Size(127, 24);
               this->BillLabel->TabIndex = 46;
               this->BillLabel->Text = L"Monthly Bill:";
               // 
               // Bill
               // 
               this->Bill->AutoSize = true;
               this->Bill->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Bill->Location = System::Drawing::Point(1088, 505);
               this->Bill->Name = L"Bill";
               this->Bill->Size = System::Drawing::Size(0, 28);
               this->Bill->TabIndex = 47;
               // 
               // button4
               // 
               this->button4->Location = System::Drawing::Point(896, 600);
               this->button4->Name = L"button4";
               this->button4->Size = System::Drawing::Size(137, 34);
               this->button4->TabIndex = 56;
               this->button4->Text = L"Clear";
               this->button4->UseVisualStyleBackColor = true;
               this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
               // 
               // Set_M_V1
               // 
               this->Set_M_V1->Location = System::Drawing::Point(227, 206);
               this->Set_M_V1->Name = L"Set_M_V1";
               this->Set_M_V1->Size = System::Drawing::Size(50, 27);
               this->Set_M_V1->TabIndex = 57;
               this->Set_M_V1->Text = L"Set";
               this->Set_M_V1->UseVisualStyleBackColor = true;
               this->Set_M_V1->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
               // 
               // Set_M_C1
               // 
               this->Set_M_C1->Location = System::Drawing::Point(227, 255);
               this->Set_M_C1->Name = L"Set_M_C1";
               this->Set_M_C1->Size = System::Drawing::Size(50, 25);
               this->Set_M_C1->TabIndex = 58;
               this->Set_M_C1->Text = L"Set";
               this->Set_M_C1->UseVisualStyleBackColor = true;
               this->Set_M_C1->Click += gcnew System::EventHandler(this, &Form1::Set_M_C1_Click);
               // 
               // Set_M_V2
               // 
               this->Set_M_V2->Location = System::Drawing::Point(517, 205);
               this->Set_M_V2->Name = L"Set_M_V2";
               this->Set_M_V2->Size = System::Drawing::Size(50, 28);
               this->Set_M_V2->TabIndex = 59;
               this->Set_M_V2->Text = L"Set";
               this->Set_M_V2->UseVisualStyleBackColor = true;
               this->Set_M_V2->Click += gcnew System::EventHandler(this, &Form1::Set_M_V2_Click);
               // 
               // Set_M_C2
               // 
               this->Set_M_C2->Location = System::Drawing::Point(517, 252);
               this->Set_M_C2->Name = L"Set_M_C2";
               this->Set_M_C2->Size = System::Drawing::Size(50, 28);
               this->Set_M_C2->TabIndex = 60;
               this->Set_M_C2->Text = L"Set";
               this->Set_M_C2->UseVisualStyleBackColor = true;
               this->Set_M_C2->Click += gcnew System::EventHandler(this, &Form1::Set_M_C2_Click);
               // 
               // Set_M_V3
               // 
               this->Set_M_V3->Location = System::Drawing::Point(808, 204);
               this->Set_M_V3->Name = L"Set_M_V3";
               this->Set_M_V3->Size = System::Drawing::Size(50, 29);
               this->Set_M_V3->TabIndex = 61;
               this->Set_M_V3->Text = L"Set";
               this->Set_M_V3->UseVisualStyleBackColor = true;
               this->Set_M_V3->Click += gcnew System::EventHandler(this, &Form1::Set_M_V3_Click);
               // 
               // Set_M_C3
               // 
               this->Set_M_C3->Location = System::Drawing::Point(808, 255);
               this->Set_M_C3->Name = L"Set_M_C3";
               this->Set_M_C3->Size = System::Drawing::Size(50, 26);
               this->Set_M_C3->TabIndex = 62;
               this->Set_M_C3->Text = L"Set";
               this->Set_M_C3->UseVisualStyleBackColor = true;
               this->Set_M_C3->Click += gcnew System::EventHandler(this, &Form1::Set_M_C3_Click);
               // 
               // Set_M_V4
               // 
               this->Set_M_V4->Location = System::Drawing::Point(1125, 205);
               this->Set_M_V4->Name = L"Set_M_V4";
               this->Set_M_V4->Size = System::Drawing::Size(61, 28);
               this->Set_M_V4->TabIndex = 63;
               this->Set_M_V4->Text = L"Set";
               this->Set_M_V4->UseVisualStyleBackColor = true;
               this->Set_M_V4->Click += gcnew System::EventHandler(this, &Form1::Set_M_V4_Click);
               // 
               // Set_M_C4
               // 
               this->Set_M_C4->Location = System::Drawing::Point(1125, 253);
               this->Set_M_C4->Name = L"Set_M_C4";
               this->Set_M_C4->Size = System::Drawing::Size(60, 28);
               this->Set_M_C4->TabIndex = 64;
               this->Set_M_C4->Text = L"Set";
               this->Set_M_C4->UseVisualStyleBackColor = true;
               this->Set_M_C4->Click += gcnew System::EventHandler(this, &Form1::Set_M_C4_Click);
               // 
               // openFileDialog2
               // 
               this->openFileDialog2->FileName = L"openFileDialog2";
               // 
               // openFileDialog3
               // 
               this->openFileDialog3->FileName = L"openFileDialog3";
               // 
               // openFileDialog4
               // 
               this->openFileDialog4->FileName = L"openFileDialog4";
               // 
               // Calculate1
               // 
               this->Calculate1->Location = System::Drawing::Point(227, 519);
               this->Calculate1->Name = L"Calculate1";
               this->Calculate1->Size = System::Drawing::Size(97, 26);
               this->Calculate1->TabIndex = 65;
               this->Calculate1->Text = L"Calculate";
               this->Calculate1->UseVisualStyleBackColor = true;
               this->Calculate1->Click += gcnew System::EventHandler(this, &Form1::Calculate1_Click);
               // 
               // Calculate2
               // 
               this->Calculate2->Location = System::Drawing::Point(227, 571);
               this->Calculate2->Name = L"Calculate2";
               this->Calculate2->Size = System::Drawing::Size(97, 23);
               this->Calculate2->TabIndex = 66;
               this->Calculate2->Text = L"Calculate";
               this->Calculate2->UseVisualStyleBackColor = true;
               this->Calculate2->Click += gcnew System::EventHandler(this, &Form1::Calculate2_Click);
               // 
               // PF1
               // 
               this->PF1->AutoSize = true;
               this->PF1->BackColor = System::Drawing::SystemColors::InfoText;
               this->PF1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->PF1->ForeColor = System::Drawing::Color::Chocolate;
               this->PF1->Location = System::Drawing::Point(12, 423);
               this->PF1->Name = L"PF1";
               this->PF1->Size = System::Drawing::Size(115, 21);
               this->PF1->TabIndex = 67;
               this->PF1->Text = L"Power Factor:";
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->BackColor = System::Drawing::SystemColors::InfoText;
               this->label1->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->ForeColor = System::Drawing::Color::Chocolate;
               this->label1->Location = System::Drawing::Point(306, 423);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(115, 21);
               this->label1->TabIndex = 68;
               this->label1->Text = L"Power Factor:";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::SystemColors::InfoText;
               this->label2->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label2->ForeColor = System::Drawing::Color::Chocolate;
               this->label2->Location = System::Drawing::Point(603, 423);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(115, 21);
               this->label2->TabIndex = 69;
               this->label2->Text = L"Power Factor:";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->BackColor = System::Drawing::SystemColors::InfoText;
               this->label3->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label3->ForeColor = System::Drawing::Color::Chocolate;
               this->label3->Location = System::Drawing::Point(918, 423);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(115, 21);
               this->label3->TabIndex = 70;
               this->label3->Text = L"Power Factor:";
               // 
               // label_value_PF1
               // 
               this->label_value_PF1->AutoSize = true;
               this->label_value_PF1->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label_value_PF1->Location = System::Drawing::Point(166, 416);
               this->label_value_PF1->Name = L"label_value_PF1";
               this->label_value_PF1->Size = System::Drawing::Size(0, 28);
               this->label_value_PF1->TabIndex = 71;
               // 
               // label_value_PF2
               // 
               this->label_value_PF2->AutoSize = true;
               this->label_value_PF2->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label_value_PF2->Location = System::Drawing::Point(450, 416);
               this->label_value_PF2->Name = L"label_value_PF2";
               this->label_value_PF2->Size = System::Drawing::Size(0, 28);
               this->label_value_PF2->TabIndex = 72;
               this->label_value_PF2->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
               // 
               // label_value_PF3
               // 
               this->label_value_PF3->AutoSize = true;
               this->label_value_PF3->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label_value_PF3->Location = System::Drawing::Point(739, 416);
               this->label_value_PF3->Name = L"label_value_PF3";
               this->label_value_PF3->Size = System::Drawing::Size(0, 28);
               this->label_value_PF3->TabIndex = 73;
               // 
               // label_value_PF4
               // 
               this->label_value_PF4->AutoSize = true;
               this->label_value_PF4->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label_value_PF4->Location = System::Drawing::Point(1066, 416);
               this->label_value_PF4->Name = L"label_value_PF4";
               this->label_value_PF4->Size = System::Drawing::Size(0, 28);
               this->label_value_PF4->TabIndex = 74;
               // 
               // button5
               // 
               this->button5->Location = System::Drawing::Point(815, 507);
               this->button5->Name = L"button5";
               this->button5->Size = System::Drawing::Size(97, 26);
               this->button5->TabIndex = 75;
               this->button5->Text = L"Calculate";
               this->button5->UseVisualStyleBackColor = true;
               this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click_1);
               // 
               // saveFileDialog1
               // 
               this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label4->Location = System::Drawing::Point(251, 309);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(52, 22);
               this->label4->TabIndex = 76;
               this->label4->Text = L"Watt";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label5->Location = System::Drawing::Point(251, 364);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(49, 24);
               this->label5->TabIndex = 77;
               this->label5->Text = L"Kwh";
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label6->Location = System::Drawing::Point(545, 309);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(52, 22);
               this->label6->TabIndex = 78;
               this->label6->Text = L"Watt";
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label7->Location = System::Drawing::Point(860, 310);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(52, 22);
               this->label7->TabIndex = 79;
               this->label7->Text = L"Watt";
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label8->Location = System::Drawing::Point(1166, 310);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(52, 22);
               this->label8->TabIndex = 80;
               this->label8->Text = L"Watt";
               // 
               // label9
               // 
               this->label9->AutoSize = true;
               this->label9->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label9->Location = System::Drawing::Point(646, 522);
               this->label9->Name = L"label9";
               this->label9->Size = System::Drawing::Size(52, 22);
               this->label9->TabIndex = 81;
               this->label9->Text = L"Watt";
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label10->Location = System::Drawing::Point(548, 364);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(49, 24);
               this->label10->TabIndex = 82;
               this->label10->Text = L"Kwh";
               // 
               // label12
               // 
               this->label12->AutoSize = true;
               this->label12->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label12->Location = System::Drawing::Point(863, 367);
               this->label12->Name = L"label12";
               this->label12->Size = System::Drawing::Size(49, 24);
               this->label12->TabIndex = 83;
               this->label12->Text = L"Kwh";
               this->label12->Click += gcnew System::EventHandler(this, &Form1::label12_Click);
               // 
               // label13
               // 
               this->label13->AutoSize = true;
               this->label13->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label13->Location = System::Drawing::Point(1169, 371);
               this->label13->Name = L"label13";
               this->label13->Size = System::Drawing::Size(49, 24);
               this->label13->TabIndex = 84;
               this->label13->Text = L"Kwh";
               // 
               // label14
               // 
               this->label14->AutoSize = true;
               this->label14->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label14->Location = System::Drawing::Point(646, 571);
               this->label14->Name = L"label14";
               this->label14->Size = System::Drawing::Size(49, 24);
               this->label14->TabIndex = 85;
               this->label14->Text = L"Kwh";
               // 
               // label15
               // 
               this->label15->AutoSize = true;
               this->label15->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label15->Location = System::Drawing::Point(1236, 505);
               this->label15->Name = L"label15";
               this->label15->Size = System::Drawing::Size(47, 28);
               this->label15->TabIndex = 86;
               this->label15->Text = L"L.E";
               // 
               // label16
               // 
               this->label16->AutoSize = true;
               this->label16->BackColor = System::Drawing::SystemColors::InfoText;
               this->label16->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label16->ForeColor = System::Drawing::Color::DarkOrange;
               this->label16->Location = System::Drawing::Point(19, 9);
               this->label16->Name = L"label16";
               this->label16->Size = System::Drawing::Size(104, 21);
               this->label16->TabIndex = 87;
               this->label16->Text = L"Instructions:";
               // 
               // label17
               // 
               this->label17->AutoSize = true;
               this->label17->BackColor = System::Drawing::SystemColors::InfoText;
               this->label17->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label17->ForeColor = System::Drawing::Color::Red;
               this->label17->Location = System::Drawing::Point(10, 30);
               this->label17->Name = L"label17";
               this->label17->Size = System::Drawing::Size(379, 21);
               this->label17->TabIndex = 88;
               this->label17->Text = L"Set max voltage and current before choosing files";
               // 
               // label18
               // 
               this->label18->AutoSize = true;
               this->label18->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label18->Location = System::Drawing::Point(1344, 101);
               this->label18->Name = L"label18";
               this->label18->Size = System::Drawing::Size(185, 28);
               this->label18->TabIndex = 89;
               this->label18->Text = L"Choose Load file:";
               // 
               // button6
               // 
               this->button6->Location = System::Drawing::Point(1349, 132);
               this->button6->Name = L"button6";
               this->button6->Size = System::Drawing::Size(137, 34);
               this->button6->TabIndex = 90;
               this->button6->Text = L"Browse";
               this->button6->UseVisualStyleBackColor = true;
               this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
               // 
               // label19
               // 
               this->label19->AutoSize = true;
               this->label19->BackColor = System::Drawing::SystemColors::InfoText;
               this->label19->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label19->ForeColor = System::Drawing::Color::Red;
               this->label19->Location = System::Drawing::Point(1290, 209);
               this->label19->Name = L"label19";
               this->label19->Size = System::Drawing::Size(111, 21);
               this->label19->TabIndex = 91;
               this->label19->Text = L"Max Voltage:";
               // 
               // label20
               // 
               this->label20->AutoSize = true;
               this->label20->BackColor = System::Drawing::SystemColors::InfoText;
               this->label20->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label20->ForeColor = System::Drawing::Color::Red;
               this->label20->Location = System::Drawing::Point(1290, 257);
               this->label20->Name = L"label20";
               this->label20->Size = System::Drawing::Size(111, 21);
               this->label20->TabIndex = 92;
               this->label20->Text = L"Max Voltage:";
               // 
               // TB_MaxVoltage5
               // 
               this->TB_MaxVoltage5->Location = System::Drawing::Point(1445, 204);
               this->TB_MaxVoltage5->Name = L"TB_MaxVoltage5";
               this->TB_MaxVoltage5->Size = System::Drawing::Size(52, 22);
               this->TB_MaxVoltage5->TabIndex = 93;
               this->TB_MaxVoltage5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged_1);
               // 
               // TB_MaxCurrent5
               // 
               this->TB_MaxCurrent5->Location = System::Drawing::Point(1445, 251);
               this->TB_MaxCurrent5->Name = L"TB_MaxCurrent5";
               this->TB_MaxCurrent5->Size = System::Drawing::Size(52, 22);
               this->TB_MaxCurrent5->TabIndex = 94;
               // 
               // Set_M_V5
               // 
               this->Set_M_V5->Location = System::Drawing::Point(1518, 203);
               this->Set_M_V5->Name = L"Set_M_V5";
               this->Set_M_V5->Size = System::Drawing::Size(61, 28);
               this->Set_M_V5->TabIndex = 95;
               this->Set_M_V5->Text = L"Set";
               this->Set_M_V5->UseVisualStyleBackColor = true;
               // 
               // Set_M_C5
               // 
               this->Set_M_C5->Location = System::Drawing::Point(1518, 250);
               this->Set_M_C5->Name = L"Set_M_C5";
               this->Set_M_C5->Size = System::Drawing::Size(61, 28);
               this->Set_M_C5->TabIndex = 96;
               this->Set_M_C5->Text = L"Set";
               this->Set_M_C5->UseVisualStyleBackColor = true;
               // 
               // label21
               // 
               this->label21->AutoSize = true;
               this->label21->BackColor = System::Drawing::SystemColors::InfoText;
               this->label21->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label21->ForeColor = System::Drawing::Color::Chocolate;
               this->label21->Location = System::Drawing::Point(1290, 302);
               this->label21->Name = L"label21";
               this->label21->Size = System::Drawing::Size(117, 21);
               this->label21->TabIndex = 97;
               this->label21->Text = L"Device Power:";
               // 
               // label22
               // 
               this->label22->AutoSize = true;
               this->label22->BackColor = System::Drawing::SystemColors::InfoText;
               this->label22->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label22->ForeColor = System::Drawing::Color::Chocolate;
               this->label22->Location = System::Drawing::Point(1290, 353);
               this->label22->Name = L"label22";
               this->label22->Size = System::Drawing::Size(124, 21);
               this->label22->TabIndex = 98;
               this->label22->Text = L"Device Energy:";
               // 
               // label23
               // 
               this->label23->AutoSize = true;
               this->label23->BackColor = System::Drawing::SystemColors::InfoText;
               this->label23->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label23->ForeColor = System::Drawing::Color::Chocolate;
               this->label23->Location = System::Drawing::Point(1290, 416);
               this->label23->Name = L"label23";
               this->label23->Size = System::Drawing::Size(115, 21);
               this->label23->TabIndex = 99;
               this->label23->Text = L"Power Factor:";
               // 
               // label24
               // 
               this->label24->AutoSize = true;
               this->label24->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label24->Location = System::Drawing::Point(1567, 295);
               this->label24->Name = L"label24";
               this->label24->Size = System::Drawing::Size(52, 22);
               this->label24->TabIndex = 100;
               this->label24->Text = L"Watt";
               // 
               // label25
               // 
               this->label25->AutoSize = true;
               this->label25->Font = (gcnew System::Drawing::Font(L"Bell MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label25->Location = System::Drawing::Point(1567, 343);
               this->label25->Name = L"label25";
               this->label25->Size = System::Drawing::Size(49, 24);
               this->label25->TabIndex = 101;
               this->label25->Text = L"Kwh";
               // 
               // label26
               // 
               this->label26->AutoSize = true;
               this->label26->BackColor = System::Drawing::SystemColors::InfoText;
               this->label26->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label26->ForeColor = System::Drawing::Color::DarkOrange;
               this->label26->Location = System::Drawing::Point(1390, 9);
               this->label26->Name = L"label26";
               this->label26->Size = System::Drawing::Size(63, 21);
               this->label26->TabIndex = 102;
               this->label26->Text = L"NOTE:";
               // 
               // label27
               // 
               this->label27->AutoSize = true;
               this->label27->BackColor = System::Drawing::SystemColors::InfoText;
               this->label27->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label27->ForeColor = System::Drawing::Color::Red;
               this->label27->Location = System::Drawing::Point(1237, 30);
               this->label27->Name = L"label27";
               this->label27->Size = System::Drawing::Size(423, 63);
               this->label27->TabIndex = 103;
               this->label27->Text = L"Only use this button if Sampling time was not recorded\r\nand set it before choosin"
                   L"g the file\r\n\r\n";
               this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
               // 
               // label28
               // 
               this->label28->AutoSize = true;
               this->label28->BackColor = System::Drawing::SystemColors::InfoText;
               this->label28->Font = (gcnew System::Drawing::Font(L"Bell MT", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label28->ForeColor = System::Drawing::Color::Red;
               this->label28->Location = System::Drawing::Point(1567, 108);
               this->label28->Name = L"label28";
               this->label28->Size = System::Drawing::Size(122, 21);
               this->label28->TabIndex = 104;
               this->label28->Text = L"Sampling time:";
               // 
               // button9
               // 
               this->button9->Location = System::Drawing::Point(1769, 106);
               this->button9->Name = L"button9";
               this->button9->Size = System::Drawing::Size(61, 28);
               this->button9->TabIndex = 105;
               this->button9->Text = L"Set";
               this->button9->UseVisualStyleBackColor = true;
               this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
               // 
               // Tsampling_TB
               // 
               this->Tsampling_TB->Location = System::Drawing::Point(1711, 109);
               this->Tsampling_TB->Name = L"Tsampling_TB";
               this->Tsampling_TB->Size = System::Drawing::Size(52, 22);
               this->Tsampling_TB->TabIndex = 106;
               // 
               // Power5
               // 
               this->Power5->AutoSize = true;
               this->Power5->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Power5->Location = System::Drawing::Point(1465, 289);
               this->Power5->Name = L"Power5";
               this->Power5->Size = System::Drawing::Size(0, 28);
               this->Power5->TabIndex = 108;
               // 
               // Energy5
               // 
               this->Energy5->AutoSize = true;
               this->Energy5->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->Energy5->Location = System::Drawing::Point(1465, 339);
               this->Energy5->Name = L"Energy5";
               this->Energy5->Size = System::Drawing::Size(0, 28);
               this->Energy5->TabIndex = 109;
               // 
               // label_value_PF5
               // 
               this->label_value_PF5->AutoSize = true;
               this->label_value_PF5->Font = (gcnew System::Drawing::Font(L"Bell MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label_value_PF5->Location = System::Drawing::Point(1465, 409);
               this->label_value_PF5->Name = L"label_value_PF5";
               this->label_value_PF5->Size = System::Drawing::Size(0, 28);
               this->label_value_PF5->TabIndex = 110;
               // 
               // openFileDialog5
               // 
               this->openFileDialog5->FileName = L"openFileDialog5";
               // 
               // Form1
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->AutoSize = true;
               this->BackColor = System::Drawing::SystemColors::ControlLight;
               this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
               this->ClientSize = System::Drawing::Size(1903, 636);
               this->Controls->Add(this->label_value_PF5);
               this->Controls->Add(this->Energy5);
               this->Controls->Add(this->Power5);
               this->Controls->Add(this->Tsampling_TB);
               this->Controls->Add(this->button9);
               this->Controls->Add(this->label28);
               this->Controls->Add(this->label27);
               this->Controls->Add(this->label26);
               this->Controls->Add(this->label25);
               this->Controls->Add(this->label24);
               this->Controls->Add(this->label23);
               this->Controls->Add(this->label22);
               this->Controls->Add(this->label21);
               this->Controls->Add(this->Set_M_C5);
               this->Controls->Add(this->Set_M_V5);
               this->Controls->Add(this->TB_MaxCurrent5);
               this->Controls->Add(this->TB_MaxVoltage5);
               this->Controls->Add(this->label20);
               this->Controls->Add(this->label19);
               this->Controls->Add(this->button6);
               this->Controls->Add(this->label18);
               this->Controls->Add(this->label17);
               this->Controls->Add(this->label16);
               this->Controls->Add(this->label15);
               this->Controls->Add(this->label14);
               this->Controls->Add(this->label13);
               this->Controls->Add(this->label12);
               this->Controls->Add(this->label10);
               this->Controls->Add(this->label9);
               this->Controls->Add(this->label8);
               this->Controls->Add(this->label7);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->label5);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->button5);
               this->Controls->Add(this->label_value_PF4);
               this->Controls->Add(this->label_value_PF3);
               this->Controls->Add(this->label_value_PF2);
               this->Controls->Add(this->label_value_PF1);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->PF1);
               this->Controls->Add(this->Calculate2);
               this->Controls->Add(this->Calculate1);
               this->Controls->Add(this->Set_M_C4);
               this->Controls->Add(this->Set_M_V4);
               this->Controls->Add(this->Set_M_C3);
               this->Controls->Add(this->Set_M_V3);
               this->Controls->Add(this->Set_M_C2);
               this->Controls->Add(this->Set_M_V2);
               this->Controls->Add(this->Set_M_C1);
               this->Controls->Add(this->Set_M_V1);
               this->Controls->Add(this->button4);
               this->Controls->Add(this->Bill);
               this->Controls->Add(this->BillLabel);
               this->Controls->Add(this->TB_MaxCurrent4);
               this->Controls->Add(this->TB_MaxVoltage4);
               this->Controls->Add(this->TB_MaxCurrent3);
               this->Controls->Add(this->TB_MaxVoltage3);
               this->Controls->Add(this->TB_MaxCurrent2);
               this->Controls->Add(this->TB_MaxVoltage2);
               this->Controls->Add(this->DeviceEnergy4);
               this->Controls->Add(this->DeviceEnergy3);
               this->Controls->Add(this->DeviceEnergy2);
               this->Controls->Add(this->Energy4);
               this->Controls->Add(this->Energy3);
               this->Controls->Add(this->Energy2);
               this->Controls->Add(this->Power4);
               this->Controls->Add(this->Power3);
               this->Controls->Add(this->Power2);
               this->Controls->Add(this->DevicePowerLabel4);
               this->Controls->Add(this->DevicePowerLabel3);
               this->Controls->Add(this->DevicePowerLabel2);
               this->Controls->Add(this->MaxCurrentLabel4);
               this->Controls->Add(this->MaxCurrentLabel3);
               this->Controls->Add(this->MaxCurrentLabel2);
               this->Controls->Add(this->MaxVoltLabel4);
               this->Controls->Add(this->MaxVoltLabel3);
               this->Controls->Add(this->MaxVoltLabel2);
               this->Controls->Add(this->EnergyTotal);
               this->Controls->Add(this->DevicesEnergy);
               this->Controls->Add(this->PowerTotal);
               this->Controls->Add(this->label11);
               this->Controls->Add(this->Energy1);
               this->Controls->Add(this->DeviceEnergy1);
               this->Controls->Add(this->Power1);
               this->Controls->Add(this->DevicePowerLabel1);
               this->Controls->Add(this->MaxCurrentLabel1);
               this->Controls->Add(this->MaxVoltLabel1);
               this->Controls->Add(this->button3);
               this->Controls->Add(this->button2);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->ChooseLabel4);
               this->Controls->Add(this->ChooseLabel3);
               this->Controls->Add(this->ChooseLabel2);
               this->Controls->Add(this->TB_MaxCurrent1);
               this->Controls->Add(this->TB_MaxVoltage1);
               this->Controls->Add(this->SaveBTN);
               this->Controls->Add(this->LoadBTN);
               this->Controls->Add(this->ChooseLabel1);
               this->Controls->Add(this->SmartMeter);
               this->MaximizeBox = false;
               this->MaximumSize = System::Drawing::Size(1921, 683);
               this->MinimizeBox = false;
               this->MinimumSize = System::Drawing::Size(1918, 683);
               this->Name = L"Form1";
               this->Text = L"Smart Meter";
               this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion
    private: System::Void LoadBTN_Click(System::Object^ sender, System::EventArgs^ e) {
        if (powerD5 == 0.0)
        {
            openFileDialog1->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath = openFileDialog1->FileName;
                MessageBox::Show("File selected: " + filePath);

                try {

                    std::string stdFilePath = msclr::interop::marshal_as<std::string>(filePath);
                    read_csv(stdFilePath, waveform);
                    period1 = getPeriod(waveform);
                    alarm(DeviceOne, waveform, period1);
                    filteration(waveform, waveform, 1000);
                    powerD1 = power.CalcPowerAverage(waveform);
                    powerTotal += powerD1;
                    Power1->Text = powerD1.ToString("0.0");

                    energyD1 = energy_c1.Ecalculator(waveform);
                    energyTotal += energyD1;
                    X = waveform.back().time;

                    Energy1->Text = energyD1.ToString("0.000");

                    load1_powerfactor = powerfactor(waveform);
                    label_value_PF1->Text = load1_powerfactor.ToString("0.000");


                    // Display the first 3 elements
                    /*
                    String^ message = "First 3 elements:\n";
                    for (size_t i = 0; i < 3 && i < waveform.size(); ++i) {
                        message += "Time: " + waveform[i].time + ", Voltage: " + waveform[i].voltage + ", Current: " + waveform[i].current + "\n";
                    }

                    MessageBox::Show(message);
                    */
                    DeviceOne.setName("First Load");

                    MessageBox::Show("File loaded successfully!");
                }
                catch (const std::exception& ex) {
                    MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
                }
            }

        }
        else {
            MessageBox::Show("You can't use this with Device 5,\n Please clear the data!");

        }

    }
    private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceOne.setMaxVolt(System::Convert::ToDouble(TB_MaxVoltage1->Text));
        MessageBox::Show("Max voltage set to " + DeviceOne.getProperty().max_cap_volt);


    }
    private: System::Void Set_M_V2_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceTwo.setMaxVolt(System::Convert::ToDouble(TB_MaxVoltage2->Text));
        MessageBox::Show("Max voltage set to " + DeviceTwo.getProperty().max_cap_volt);
    }
    private: System::Void Set_M_V3_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceThree.setMaxVolt(System::Convert::ToDouble(TB_MaxVoltage3->Text));
        MessageBox::Show("Max voltage set to " + DeviceThree.getProperty().max_cap_volt);
    }
    private: System::Void Set_M_V4_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceFour.setMaxVolt(System::Convert::ToDouble(TB_MaxVoltage4->Text));
        MessageBox::Show("Max voltage set to " + DeviceFour.getProperty().max_cap_volt);
    }
    private: System::Void Set_M_C1_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceOne.setMaxCurrent(System::Convert::ToDouble(TB_MaxCurrent1->Text));
        MessageBox::Show("Max current set to " + DeviceOne.getProperty().max_cap_current);
    }
    private: System::Void Set_M_C2_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceTwo.setMaxCurrent(System::Convert::ToDouble(TB_MaxCurrent2->Text));
        MessageBox::Show("Max current set to " + DeviceTwo.getProperty().max_cap_current);
    }
    private: System::Void Set_M_C3_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceThree.setMaxCurrent(System::Convert::ToDouble(TB_MaxCurrent3->Text));
        MessageBox::Show("Max current set to " + DeviceThree.getProperty().max_cap_current);
    }
    private: System::Void Set_M_C4_Click(System::Object^ sender, System::EventArgs^ e) {
        DeviceFour.setMaxCurrent(System::Convert::ToDouble(TB_MaxCurrent4->Text));
        MessageBox::Show("Max current set to " + DeviceFour.getProperty().max_cap_current);
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (powerD5 == 0.0)
        {
            openFileDialog2->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath2 = openFileDialog2->FileName;
                MessageBox::Show("File selected: " + filePath2);

                try {

                    std::string stdFilePath2 = msclr::interop::marshal_as<std::string>(filePath2);
                    read_csv(stdFilePath2, waveform2);

                    period2 = getPeriod(waveform2);

                    alarm(DeviceTwo, waveform2, period2);

                    filteration(waveform2, waveform2, 1000);

                    powerD2 = power.CalcPowerAverage(waveform2);
                    Power2->Text = powerD2.ToString("0.0");
                    powerTotal += powerD2;

                    energyD2 = energy_c2.Ecalculator(waveform2);
                    energyTotal += energyD2;
                    Energy2->Text = energyD2.ToString("0.000");
                    X = waveform2.back().time;

                    load2_powerfactor = powerfactor(waveform2);
                    label_value_PF2->Text = load2_powerfactor.ToString("0.000");


                    // Display the first 3 elements
                    /*
                    String^ message = "First 3 elements:\n";
                    for (size_t i = 0; i < 3 && i < waveform2.size(); ++i) {
                        message += "Time: " + waveform2[i].time + ", Voltage: " + waveform2[i].voltage + ", Current: " + waveform2[i].current + "\n";
                    }
                    MessageBox::Show(message);
                    */
                    DeviceTwo.setName("Second Load");

                    MessageBox::Show("File loaded successfully!");
                }
                catch (const std::exception& ex) {
                    MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
                }
            }
        }
        else {
            MessageBox::Show("You can't use this with Device 5,\n Please clear the data!");

        }

    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        if (powerD5 == 0.0) {
            openFileDialog3->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openFileDialog3->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath3 = openFileDialog3->FileName;
                MessageBox::Show("File selected: " + filePath3);

                try {

                    std::string stdFilePath3 = msclr::interop::marshal_as<std::string>(filePath3);
                    read_csv(stdFilePath3, waveform3);
                    period3 = getPeriod(waveform3);
                    alarm(DeviceThree, waveform3, period3);
                    filteration(waveform3, waveform3, 1000);
                    powerD3 = power.CalcPowerAverage(waveform3);
                    powerTotal += powerD3;
                    Power3->Text = powerD3.ToString("0.0");

                    energyD3 = energy_c3.Ecalculator(waveform3);
                    energyTotal += energyD3;
                    X = waveform3.back().time;

                    Energy3->Text = energyD3.ToString("0.000");
                    load3_powerfactor = powerfactor(waveform3);
                    label_value_PF3->Text = load3_powerfactor.ToString("0.000");

                    // Display the first 3 elements
                  /*  String^ message = "First 3 elements:\n";
                    for (size_t i = 0; i < 3 && i < waveform3.size(); ++i) {
                        message += "Time: " + waveform3[i].time + ", Voltage: " + waveform3[i].voltage + ", Current: " + waveform3[i].current + "\n";
                    }
                    MessageBox::Show(message);
                    */
                    DeviceThree.setName("Third Load");

                    MessageBox::Show("File loaded successfully!");
                }
                catch (const std::exception& ex) {
                    MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
                }
            }
        }
        else {
            MessageBox::Show("You can't use this with Device 5,\n Please clear the data!");

        }
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        if (powerD5 == 0.0) {
            openFileDialog4->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openFileDialog4->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath4 = openFileDialog4->FileName;
                MessageBox::Show("File selected: " + filePath4);

                try {

                    std::string stdFilePath4 = msclr::interop::marshal_as<std::string>(filePath4);
                    read_csv(stdFilePath4, waveform4);
                    alarm(DeviceFour, waveform4, period4);
                    period4 = getPeriod(waveform4);
                    filteration(waveform4, waveform4, 1000);
                    powerD4 = power.CalcPowerAverage(waveform4);
                    powerTotal += powerD4;
                    Power4->Text = powerD4.ToString("0.0");

                    energyD4 = energy_c4.Ecalculator(waveform4);
                    energyTotal += energyD4;
                    X = waveform4.back().time;

                    Energy4->Text = energyD4.ToString("0.000");
                    load4_powerfactor = powerfactor(waveform4);
                    label_value_PF4->Text = load4_powerfactor.ToString("0.0");


                    // Display the first 3 elements
                    /*
                    String^ message = "First 3 elements:\n";
                    for (size_t i = 0; i < 3 && i < waveform4.size(); ++i) {
                        message += "Time: " + waveform4[i].time + ", Voltage: " + waveform4[i].voltage + ", Current: " + waveform4[i].current + "\n";
                    }
                    MessageBox::Show(message);
                    */
                    DeviceTwo.setName("Fourth Load");

                    MessageBox::Show("File loaded successfully!");
                }
                catch (const std::exception& ex) {
                    MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
                }
            }
        }
        else {
            MessageBox::Show("You can't use this with Device 5,\n Please clear the data!");

        }
    }
    private: System::Void Calculate1_Click(System::Object^ sender, System::EventArgs^ e) {
        PowerTotal->Text = powerTotal.ToString("0.000");




    }
    private: System::Void Calculate2_Click(System::Object^ sender, System::EventArgs^ e) {

        EnergyTotal->Text = energyTotal.ToString("0.000");
    }
 private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
     // Reset home_appliance instances
     DeviceOne = home_appliance();
     DeviceTwo = home_appliance();
     DeviceThree = home_appliance();
     DeviceFour = home_appliance();
     DeviceFive = home_appliance();

     // Clear waveform vectors
     waveform.clear();
     waveform2.clear();
     waveform3.clear();
     waveform4.clear();
     waveform5.clear();

     // Reset powercalculator instance
     power = powercalculator();

     // Reset energycalc instances
     energy_c1 = energycalc();
     energy_c2 = energycalc();
     energy_c3 = energycalc();
     energy_c4 = energycalc();
     energy_c5 = energycalc();

     // Reset energy values
     energyD1 = 0.0;
     energyD2 = 0.0;
     energyD3 = 0.0;
     energyD4 = 0.0;
     energyD5 = 0.0;
     energyTotal = 0.0;

     // Reset power values
     powerD1 = 0.0;
     powerD2 = 0.0;
     powerD3 = 0.0;
     powerD4 = 0.0;
     powerD5 = 0.0;
     powerTotal = 0.0;

     // Clear period vectors
     period1.clear();
     period2.clear();
     period3.clear();
     period4.clear();
     period5.clear();

     //clear load
     load1_powerfactor = 0.0;
     load2_powerfactor = 0.0;
     load3_powerfactor = 0.0;
     load4_powerfactor = 0.0;
     load5_powerfactor = 0.0;

     //clear bill

     total_bill = 0.0;

     X = 0.0;
     // Clear labels and text boxes
     Power1->Text = "";
     Energy1->Text = "";
     Power2->Text = "";
     Energy2->Text = "";
     Power3->Text = "";
     Energy3->Text = "";
     Power4->Text = "";
     Energy4->Text = "";
     Power5->Text = "";
     Energy5->Text = "";
     PowerTotal->Text = "";
     EnergyTotal->Text = "";
     TB_MaxVoltage1->Text = "";
     TB_MaxCurrent1->Text = "";
     TB_MaxVoltage2->Text = "";
     TB_MaxCurrent2->Text = "";
     TB_MaxVoltage3->Text = "";
     TB_MaxCurrent3->Text = "";
     TB_MaxVoltage4->Text = "";
     TB_MaxCurrent4->Text = "";
     TB_MaxVoltage5->Text = "";
     TB_MaxCurrent5->Text = "";
     Tsampling_TB->Text   = "";
     label_value_PF1->Text = "";
     label_value_PF2->Text = "";
     label_value_PF3->Text = "";
     label_value_PF4->Text = "";
     label_value_PF5->Text = "";
     click_sampling = 0;
     TSampling= 0.0;
     Bill->Text = "";

     // show a message that all fields were cleared
     MessageBox::Show("All data and fields have been cleared.", "Clear Data", MessageBoxButtons::OK, MessageBoxIcon::Information);
 }


private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
    total_bill = getbill(energyTotal,X);
    Bill->Text = total_bill.ToString("0.000");
}
       







private: System::Void SaveBTN_Click(System::Object^ sender, System::EventArgs^ e) {
    saveFileDialog1->Title = "Save Data File";
    saveFileDialog1->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
    saveFileDialog1->DefaultExt = "csv";
    saveFileDialog1->AddExtension = true;

    if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        System::String^ filePath = saveFileDialog1->FileName;

        // Call a function to save data to CSV file
        SaveDataToCSV(filePath, powerD1, energyD1, load1_powerfactor, powerD2, energyD2, load2_powerfactor, powerD3, energyD3, load3_powerfactor, powerD4, energyD4, load4_powerfactor, powerD5, energyD5, load5_powerfactor, total_bill, energyTotal, powerTotal, waveform, waveform2, waveform3, waveform4, waveform5);

        System::Windows::Forms::MessageBox::Show("Data saved to: " + filePath);
    }
}

       void SaveDataToCSV(System::String^ filePath, double power1, double energy1, double powerFactor1, double power2, double energy2, double powerFactor2, double power3, double energy3, double powerFactor3, double power4, double energy4, double powerFactor4, double power5, double energy5, double powerFactor5, double totalBill, double energyTotal, double powerTotal, std::vector<signal> waveform, std::vector<signal> waveform2, std::vector<signal> waveform3, std::vector<signal> waveform4, std::vector<signal> waveform5) {
           // Convert managed String^ to unmanaged std::string
           std::string stdFilePath = msclr::interop::marshal_as<std::string>(filePath);

           // Open file stream
           std::ofstream file(stdFilePath);

           // Check if file is open
           if (file.is_open()) {
               // Write header for device data
               file << "Device,Power,Energy,Power Factor\n";

               // Write data for each device
               file << "Device 1," << power1 << "," << energy1 << "," << powerFactor1 << "\n";
               file << "Device 2," << power2 << "," << energy2 << "," << powerFactor2 << "\n";
               file << "Device 3," << power3 << "," << energy3 << "," << powerFactor3 << "\n";
               file << "Device 4," << power4 << "," << energy4 << "," << powerFactor4 << "\n";
               file << "Device 5," << power5 << "," << energy5 << "," << powerFactor5 << "\n";

               // Write total values
               file << "Total,,,\n"; // Add an empty line
               file << "Power Total," << powerTotal << "\n";
               file << "Energy Total," << energyTotal << "\n";
               file << "Total Bill," << totalBill << "\n";

#ifdef max 
#undef max
#endif

               // Write headers for waveforms if any waveform is not empty
               bool hasWaveform = !waveform.empty() || !waveform2.empty() || !waveform3.empty() || !waveform4.empty() || !waveform5.empty();

               if (hasWaveform) {
                   file << "\n";

                   if (!waveform.empty()) {
                       file << ",Device One Filtered,,,"; // Centered above waveform 1
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform2.empty()) {
                       file << ",Device Two Filtered,,,"; // Centered above waveform 2
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform3.empty()) {
                       file << ",Device Three Filtered,,,"; // Centered above waveform 3
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform4.empty()) {
                       file << ",Device Four Filtered,,,"; // Centered above waveform 4
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform5.empty()) {
                       file << ",Device Five Filtered"; // Centered above waveform 5
                   }
                   file << "\n";

                   // Write Time, Voltage, Current headers
                   if (!waveform.empty()) {
                       file << "Time,Voltage,Current,,,";
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform2.empty()) {
                       file << "Time,Voltage,Current,,,";
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform3.empty()) {
                       file << "Time,Voltage,Current,,,";
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform4.empty()) {
                       file << "Time,Voltage,Current,,,";
                   }
                   else {
                       file << ",,,,,,";
                   }
                   if (!waveform5.empty()) {
                       file << "Time,Voltage,Current";
                   }
                   file << "\n";
               }

               // Determine the maximum number of rows for the waveforms
               size_t maxRows = std::max({ waveform.size(), waveform2.size(), waveform3.size(), waveform4.size(), waveform5.size() });

               // Write waveform data side by side with 3 empty columns between each
               for (size_t i = 0; i < maxRows; ++i) {
                   // Write waveform 1
                   if (i < waveform.size()) {
                       file << waveform[i].time << "," << waveform[i].voltage << "," << waveform[i].current;
                   }
                   else {
                       file << ",,,";
                   }
                   if (!waveform2.empty() || !waveform3.empty() || !waveform4.empty() || !waveform5.empty()) {
                       file << ",,,"; // 3 Empty columns
                   }

                   // Write waveform 2
                   if (i < waveform2.size()) {
                       file << waveform2[i].time << "," << waveform2[i].voltage << "," << waveform2[i].current;
                   }
                   else {
                       file << ",,,";
                   }
                   if (!waveform3.empty() || !waveform4.empty() || !waveform5.empty()) {
                       file << ",,,"; // 3 Empty columns
                   }

                   // Write waveform 3
                   if (i < waveform3.size()) {
                       file << waveform3[i].time << "," << waveform3[i].voltage << "," << waveform3[i].current;
                   }
                   else {
                       file << ",,,";
                   }
                   if (!waveform4.empty() || !waveform5.empty()) {
                       file << ",,,"; // 3 Empty columns
                   }

                   // Write waveform 4
                   if (i < waveform4.size()) {
                       file << waveform4[i].time << "," << waveform4[i].voltage << "," << waveform4[i].current;
                   }
                   else {
                       file << ",,,";
                   }
                   if (!waveform5.empty()) {
                       file << ",,,"; // 3 Empty columns
                   }

                   // Write waveform 5
                   if (i < waveform5.size()) {
                       file << waveform5[i].time << "," << waveform5[i].voltage << "," << waveform5[i].current;
                   }
                   file << "\n"; // New line for next set of data
               }

               // Close file
               file.close();
           }
           else {
               System::Windows::Forms::MessageBox::Show("Unable to open file: " + filePath);
           }
       }


private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void DeviceEnergy4_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
    click_sampling = 1;
    TSampling=(System::Convert::ToDouble(Tsampling_TB->Text));
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
    if (powerD1 == 0.0 && powerD2 == 0.0 && powerD3 == 0.0 && powerD4 == 0.0)
    {
        if (click_sampling)
        {
            openFileDialog5->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openFileDialog5->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath5 = openFileDialog5->FileName;
                MessageBox::Show("File selected: " + filePath5);

                try {

                    std::string stdFilePath5 = msclr::interop::marshal_as<std::string>(filePath5);
                    read_csv(stdFilePath5, waveform5, TSampling);
                    alarm(DeviceFive, waveform5, period5);
                    period5 = getPeriod(waveform5);
                    filteration(waveform5, waveform5, 1000);
                    powerD5 = power.CalcPowerAverage(waveform5);
                    powerTotal += powerD5;
                    Power5->Text = powerD5.ToString("0.0");

                    energyD5 = energy_c5.Ecalculator(waveform5);
                    energyTotal += energyD5;
                    X = waveform5.back().time;

                    Energy5->Text = energyD5.ToString("0.000");
                    load5_powerfactor = powerfactor(waveform5);
                    label_value_PF5->Text = load5_powerfactor.ToString("0.0");


                    // Display the first 3 elements
                    /*
                    String^ message = "First 3 elements:\n";
                    for (size_t i = 0; i < 3 && i < waveform4.size(); ++i) {
                        message += "Time: " + waveform4[i].time + ", Voltage: " + waveform4[i].voltage + ", Current: " + waveform4[i].current + "\n";
                    }
                    MessageBox::Show(message);
                    */
                    DeviceTwo.setName("Fifth Load");

                    MessageBox::Show("File loaded successfully!");
                }
                catch (const std::exception& ex) {
                    MessageBox::Show("An error occurred: " + gcnew String(ex.what()));
                }
            }




        }
        else
        {
            MessageBox::Show("Set sampling time first please! ");
        }
    }
    else
    {
        MessageBox::Show("You can only use this alone!\n Please clear the data!");
    }
}
       private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
       }
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
       }