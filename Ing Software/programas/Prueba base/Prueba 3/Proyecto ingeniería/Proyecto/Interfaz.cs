using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime;
using System.Collections;

namespace Proyecto
{
    public partial class Interfaz : Form
    {
        public Interfaz()
        {
            
            InitializeComponent();
        }

        private void label6_Click(object sender, EventArgs e)
        {
            // NO AGREGAR NADA
        }

        private void Interfaz_Load(object sender, EventArgs e)
        {
            // NADA
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != null)
            {
                Cliente h1 = new Cliente(Int32.Parse(textBox5.Text), textBox2.Text, textBox4.Text, textBox3.Text, Int32.Parse(textBox8.Text), textBox7.Text, textBox6.Text, Int32.Parse(textBox10.Text));
                EdoCuenta e1 = new EdoCuenta(textBox1.Text, h1, ArrayListGlobal.lista);
                BD.Insertar(e1);
                ArrayListGlobal.lista.Clear();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 0)
            {
                Consumos c1 = new Consumos(comboBox1.Text, Int32.Parse(textBox11.Text), "01", numericUpDown1.Value);
                ArrayListGlobal.lista.Add(c1);
            }
            if (comboBox1.SelectedIndex == 1)
            {
                Consumos c1 = new Consumos(comboBox1.Text, Int32.Parse(textBox11.Text), "02", numericUpDown1.Value);
                ArrayListGlobal.lista.Add(c1);
            }
            if (comboBox1.SelectedIndex == 2)
            {
                Consumos c1 = new Consumos(comboBox1.Text, Int32.Parse(textBox11.Text), "03", numericUpDown1.Value);
                ArrayListGlobal.lista.Add(c1);
            }
            if (comboBox1.SelectedIndex == 3)
            {
                Consumos c1 = new Consumos(comboBox1.Text, Int32.Parse(textBox11.Text), "04", numericUpDown1.Value);
                ArrayListGlobal.lista.Add(c1);
            }
            if (comboBox1.SelectedIndex == 4)
            {
                Consumos c1 = new Consumos(comboBox1.Text, Int32.Parse(textBox11.Text), "05", numericUpDown1.Value);
                ArrayListGlobal.lista.Add(c1);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox9.Text != null)
            {
                BD.Buscar(textBox9.Text);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox9.Text != null)
            {
                BD.Borrar(textBox9.Text);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != null && textBox9.Text != null)
            {
                Cliente h1 = new Cliente(Int32.Parse(textBox5.Text), textBox2.Text, textBox4.Text, textBox3.Text, Int32.Parse(textBox8.Text), textBox7.Text, textBox6.Text, Int32.Parse(textBox10.Text));
                EdoCuenta e1 = new EdoCuenta(textBox1.Text, h1, ArrayListGlobal.lista);
                BD.Actualizar(e1, textBox9.Text);
                ArrayListGlobal.lista.Clear();
            }
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }
    }
}
