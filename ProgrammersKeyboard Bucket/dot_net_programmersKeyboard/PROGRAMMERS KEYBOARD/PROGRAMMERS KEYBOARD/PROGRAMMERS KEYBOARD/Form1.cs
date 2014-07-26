using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace PROGRAMMERS_KEYBOARD
{
    public partial class Form1 : Form
    {
        public int langSelectId;
        public Form1()
        {
            InitializeComponent();
            langSelectId = 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            langSelectId = comboBox1.SelectedIndex;
            try
            {
                if (button1.Text == "CONNECT")
                {
                    button1.Text = "DISCONNECT";
                    toolStripStatusLabel1.Text = "Your are Connected";
                    comboBox2.Enabled = false;
                    serialcommunicationport();
                    return;
                }
                else
                {
                    //disconnect portion
                    button1.Text = "CONNECT";
                    toolStripStatusLabel1.Text = "You are Not Connected";
                    comboBox2.Enabled = true;
                    serialPort1.Close();
                }
            }

            catch (Exception exe)
            {
                MessageBox.Show(exe.Message);
                button1.Text = "CONNECT";
                toolStripStatusLabel1.Text = "You are Not Connected";
                comboBox2.Enabled = true;
                serialPort1.Close();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button1.Text = "CONNECT";
            getportlist();

            toolStripStatusLabel1.Text = "You are Not CONNECT";
            comboBox1.SelectedIndex = 0;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //this.WindowState = FormWindowState.Minimized;
            this.Hide();
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.BalloonTipTitle = "Programmers Keyboard v1.0 ";
            notifyIcon1.BalloonTipText = "Programmers Keyboard Application is here in tray icon set.";


            notifyIcon1.ShowBalloonTip(5000);
        }

        private void notifyIcon1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void applicationRestoreToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Show();
            this.WindowState = FormWindowState.Normal;
        }

        private void aboutApplicationToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutBox1 abtbx = new AboutBox1();
            abtbx.ShowDialog();
        }

        private void exitProgrammersKeyboardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            getportlist();
        }
        void getportlist()
        {
            int i = 0;
            comboBox2.Items.Clear();
            // Get a list of serial port names. 
            string[] ports = SerialPort.GetPortNames();
            Console.WriteLine("The following serial ports were found:");
            foreach (string port in ports)
            {
                i++;
                comboBox2.Items.Add(port);
            }
            if (i == 0)
            {
                comboBox2.Items.Add("Not Found");
                button1.Enabled = false;
                comboBox2.SelectedIndex = 0;
            }
            else
            {
                comboBox2.SelectedIndex = 0;
                button1.Enabled = true;
            }
        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }
        void serialcommunicationport()   //serial port Commuication............
        {
            serialPort1.PortName = comboBox2.Text;
            serialPort1.BaudRate = 9600;
            serialPort1.Parity = Parity.None;
            serialPort1.StopBits = StopBits.One;
            serialPort1.Handshake = Handshake.None;
            serialPort1.Open();
            serialPort1.ReadTimeout = 200;
            //if (serialPort1.IsOpen)
            //{

            //}
            serialPort1.DataReceived += new SerialDataReceivedEventHandler(datareceived);
        }
        void datareceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            //now the received data will be send to the focused window...
            string str;
            str = serialPort1.ReadExisting();
            simulateKeys(str);

        }


        void simulateKeys(string s)   //all functions call here...............
        {
            
            switch (langSelectId + 1)
            {
                case 1:
                    //c
                    SimulateKeyCLang(s); //calling function in C Language..................
                    break;
                case 2:
                    //c++
                    SimulateKeyCppLang(s);
                    break;
                case 3:
                    //java
                    SimulateKeyjavaLang(s);
                    break;
                case 4:
                    
                    //c#
                    SimulateKeycsharpLang(s);
                    break;
                case 5:
                    //vb
                    SimulateKeyvbLang(s);
                    break;
            }
             
            //SimulateKeyCLang(s);
        }
        void SimulateKeyCLang(string s) //coding of c part
        {
            if (s == "A") //
            {
                // the snippet of if else block will be printed..
                SendKeys.SendWait("if{(}{)}{ENTER}{{}{ENTER}{TAB}//if-else block goes here...{Enter} {}}{ENTER}");
                SendKeys.Flush();
                SendKeys.SendWait("else{ENTER}{{}{ENTER}{TAB}//else block goes here....{ENTER} {}}{ENTER}");
                SendKeys.Flush();
            }
            else if (s == "B") //else...if ladder.....condition..............
            {
                SendKeys.SendWait("if{(}{)}{ENTER}{{}{ENTER}{TAB}//if-else-else-if-else block goes here...{Enter} {}}{ENTER}");
                SendKeys.SendWait("else if{(}{)} {ENTER}{{} {ENTER} {TAB}//else-if block goes here....{ENTER} {}} {ENTER}");
                SendKeys.SendWait("else{ENTER}{{}{ENTER}{TAB}//else block goes here....{ENTER} {}}{ENTER}");
            }
            else if (s == "C") //switch case condition in C...........
            {
                SendKeys.SendWait("switch {(} {)} {ENTER} {{} {ENTER} {TAB} case : {ENTER} {TAB} break ; {ENTER} {TAB} default : {ENTER} {TAB} break ; {}} {ENTER}");
            }
            else if (s == "D") //while case in c Language.........
            {
                SendKeys.SendWait("while {(}{)} {ENTER} {{} {ENTER} {TAB} //WHILE LOOP {ENTER} {}} {ENTER}");
            }
            else if (s == "E") //do.....while... Loop in C Language.............
            {
                SendKeys.SendWait("do {ENTER} {{} {ENTER} {TAB}//BODY OF DO...WHILE LOOP {ENTER} {}} while {(} condition {)} ;{ENTER}");
            }
            else if (s == "F") // for....loop...........
            {
                SendKeys.SendWait("for{(} int i{=} //initalization ;{ENTER} i <condition>;{ENTER} i{+}{+}/{-}{-} {)} {ENTER} {{} {ENTER} {TAB} //body of the loop {ENTER} {}} {ENTER}");
            }
            else if (s == "G") //  main fuction in C Languaue...............
            {
                SendKeys.SendWait("int main {(} {)} {ENTER} {{} {ENTER} {TAB} //main boday {ENTER} return 0; {ENTER} {}} {ENTER} ");
            }
            else if (s == "H") // structure.............
            {
                SendKeys.SendWait("typedef struct {<}struct_name{>} {ENTER} {{} {ENTER} {TAB} {<}data_type{>}{<}variable_name{>}; {ENTER} {TAB} {<}structure variables{>}; {ENTER} {}}; {ENTER}");
            }
            else if (s == "I") //Union.............
            {
                SendKeys.SendWait("union {<} union_name{>} {ENTER} {{} {ENTER} {TAB} {<}data_type{>}{<}variable_name{>}; {ENTER} {}} {<}union.variables{>}; {ENTER} ");

            }
            else if (s == "J") //enum..............
            {
                SendKeys.SendWait("enum {<}datatype_name{>} {ENTER} {{} {ENTER} var1 {ENTER} var2 {ENTER} var3 {ENTER} var4 {ENTER} {}} {<}enum_variable{>}; {ENTER} ");
            }
            else if (s == "K") //it is a coding of user defind function .............. it is for all Language.....
            {
                
            }

        }

        void SimulateKeyCppLang(string p) //coding of C++ part
        {
            if (p == "A") //if..else.. condtion in C++ coding................
            {
                SendKeys.SendWait("if {(} expression {)} {ENTER} {{} {ENTER} {TAB} STATEMENTS; {ENTER} {}}{ENTER}");
                SendKeys.SendWait("else {ENTER} {{} {ENTER} {TAB} //STATEMENTS; {}} {ENTER}");
            }
            else if (p == "B") //else....if condition in C++ Languaue................
            {
                SendKeys.SendWait("if{(}{)}{ENTER}{{}{ENTER}{TAB}//if-else-else-if-else block goes here...{Enter} {}}{ENTER}");
                SendKeys.SendWait("else if{(}{)} {ENTER}{{} {ENTER} {TAB}//else-if block goes here....{ENTER} {}} {ENTER}");
                SendKeys.SendWait("else{ENTER}{{}{ENTER}{TAB}//else block goes here....{ENTER} {}}{ENTER}");
            }
            else if (p == "C") //switch case condition...................
            {
                SendKeys.SendWait("switch {(} variable_name {)} {ENTER} {{} {ENTER} case constant_expression_1; {ENTER} statements; {ENTER} break; {ENTER} default: {ENTER} {TAB} statement; {ENTER} {}} {ENTER}");
            }
            else if (p == "D") //while case condition......................
            {
                SendKeys.SendWait("while {(} expression {)} {ENTER} {{} {ENTER} {TAB} statement; {ENTER} {}} {ENTER}");
            }
            else if (p == "E") //do...while loop inC++..................
            {
                SendKeys.SendWait("do {ENTER} {{} {ENTER} {TAB} statement; {ENTER} {}} while {(} boolean_expression {)} ;{ENTER}");
            }
            else if (p == "F") //for loop inC++
            {
                SendKeys.SendWait("for{(} int i{=} //initalization ;{ENTER} i <condition>;{ENTER} i{+}{+}/{-}{-} {)} {ENTER} {{} {ENTER} {TAB} //body of the loop {ENTER} {}} {ENTER}");
            }
        }
        void SimulateKeyjavaLang(string v)   //coding of Java Language....................
        {
            if (v == "A") //if....else..conditionn in java...........
            {
                SendKeys.SendWait("if {(} condition {)} {ENTER} {TAB} statement 1; {ENTER} else {ENTER} {TAB} statement 2; {ENTER}");
            }
            else if (v == "B") //else...if ladder in java............
            {
                SendKeys.SendWait("if {(} condition {)} {ENTER} {TAB} statement; else if {(} condition {)} {ENTER} {TAB} statement; {ENTER} else {ENTER} {TAB} statement{ENTER};");
            }
            else if (v == "C") //switch case in java............
            {
                SendKeys.SendWait("switch {(} expression {)} {ENTER} {{} {ENTER} {TAB} case value 1: {ENTER} {TAB} statement {ENTER} ...{ENTER} case value n: {ENTER} {TAB} statement; {ENTER} default: {ENTER} {TAB} statement; {ENTER} {}} {ENTER} ;");
            }
            else if (v == "D") //for loop in java..............
            {
                SendKeys.SendWait("for{(} int i{=} //initalization ;{ENTER} i <condition>;{ENTER} i{+}{+}/{-}{-} {)} {ENTER} {{} {ENTER} {TAB} statement block {ENTER} {}} {ENTER} ");
            }
            else if (v == "E") //while loop in java................
            {
                SendKeys.SendWait("while {(} condition {)} {ENTER} {{} {ENTER} {TAB} statement block {ENTER} {}} {ENTER}");
            }
            else if (v == "F") //do...while loop in java............
            {

                SendKeys.SendWait("do {ENTER} {{} {ENTER} {TAB} statement block {}}while {(} condition {)} ; {ENTER} ");
            }
        }
        void SimulateKeyvbLang(string r) //Coding of VB Languaue................
        {
            if (r == "A") //if...else.... condition in vb............
            {
                SendKeys.SendWait("If {(} condition {)} Then {ENTER} {TAB} statement block {ENTER} End If {ENTER}");
            }

            else if (r == "B") //else...if condition in vb............
            {
                SendKeys.SendWait("If condition Then {ENTER} {statement} Else If condition-n Then {ENTER} {TAB} //elseif statement {ENTER} Else {ENTER} {TAB} //else statement {ENTER} EndIf {ENTER}");
            }
            else if (r == "C") // while loop in vb..............
            {
                SendKeys.SendWait("Do {[}{{} While {|} Until {}} condition {]} {ENTER} {TAB} statement {ENTER} {TAB} ExitDo {ENTER} {TAB} statement {ENTER} Loop {ENTER}");
            }
            else if (r == "D") //for loop in vb................
            {
                SendKeys.SendWait("For index {=} start To End {ENTER} {TAB} //statement {ENTER} {TAB} ExitFor {ENTER} {TAB} //statement {ENTER} Next {[} index {]} {ENTER}");
            }
            else if (r == "E") //for each statement in vb........................
            {
                SendKeys.SendWait("For Each element In group {ENTER} {TAB} //statement {ENTER} ExitFor {ENTER} {TAB} //statement {ENTER} Next {[}element {]} {ENTER}");
            }
            else if (r == "F") //while condition............... in vb
            {
                SendKeys.SendWait("While condition {ENTER}{TAB} statement {ENTER} End While");
            }
            else if (r == "G") //with condition...........in vb
            {
                SendKeys.SendWait("With object {ENTER} {TAB} statement {ENTER} End With");
            }
            else if (r == "H")
            {
                SendKeys.SendWait("Select Case testcondition {ENTER} //statement {ENTER} Case Else {ENTER} {TAB} else statement {ENTER} End select {ENTER}");
            }
        }
        void SimulateKeycsharpLang(string a) //c# Language coding........
        {
            if (a == "A")   //if....else...statement......
            {
                SendKeys.SendWait("if {(}bolean expression{)} {ENTER} {{} {ENTER} {TAB} //true block statement {ENTER} {}} else {{} {ENTER} {TAB} //false statement {}} {ENTER} statement-x {ENTER}");
                return;
            }
            else if (a == "B")  //ladder if statement.....
            {
                SendKeys.SendWait("if {(} condition 1 {)} {ENTER} {TAB} statement-1; {ENTER} else if {(} condition-2 {)} {ENTER} {TAB} statement-2; {ENTER} else if {(} condition 3 {)} {ENTER} {TAB} statement-3; {ENTER} .... {ENTER} else if {(} condition n{)} {ENTER} {TAB} statement-n; {ENTER} else {ENTER} default statement; {ENTER} statement-x {ENTER}");
            }
            else if (a == "C")
            {
                SendKeys.SendWait("switch {(} expression {)} {ENTER} {{} {ENTER} {TAB} case value-1 {ENTER} {TAB} block-1; {ENTER} {TAB} break; {ENTER} case value-2 {ENTER} {TAB} block-2; {ENTER} {TAB} break; {ENTER} ...{ENTER} default; {ENTER} {TAB} default block; {ENTER} {TAB} break; {ENTER} {}} {ENTER} statement-x; {ENTER} ");
            }
            else if (a == "D") //while loop......
            {
                SendKeys.SendWait("while {(} test condition {)} {ENTER} {{} {ENTER} {TAB} //BODY OF WHILE LOOP {ENTER} {}} {ENTER} ");
            }
            else if (a == "E") //Do....while..loop.......
            {
                SendKeys.SendWait("do {ENTER} {{} {ENTER} {TAB} //body of do loop {ENTER} {}} {ENTER} while {(} test condition {)};; {ENTER}");
            }
            else if (a == "F") //for loop 
            {
                SendKeys.SendWait("for{(} int i{=} //initalization ;{ENTER} i <condition>;{ENTER} i{+}{+}/{-}{-} {)} {ENTER} {{} {ENTER} {TAB} //body of the loop {ENTER} {}} {ENTER}");
            }
            else if (a == "G") //FOR ...EACH LOOP............
            {
                SendKeys.SendWait("foreach {(}type variable in expression {)} {ENTER} {{} {ENTER} {TAB} //  body of foreach loop {ENTER} {}} {ENTER}");
            }
        }
       
    }
}

