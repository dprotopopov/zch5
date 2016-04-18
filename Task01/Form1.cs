using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Task01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void UpdateTotal()
        {
            var value = 0.0;
            for (var i = 0; i < dataGridView1.Rows.Count; i++)
            {
                var v = Convert.ToDouble(dataGridView1[0, i].EditedFormattedValue);
                var k = Convert.ToDouble(dataGridView1[1, i].EditedFormattedValue);
                var q = Convert.ToDouble(dataGridView1[2, i].EditedFormattedValue);
                var c = Convert.ToDouble(dataGridView1[3, i].EditedFormattedValue);
                value += k*v + (q/(v + c));
            }
            numericUpDown6.Value = (decimal) value;
        }

        /// <summary>
        ///     Чтение файла с параметрами задачи
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openFile_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() != DialogResult.OK) return;
            using (var reader = File.OpenText(openFileDialog1.FileName))
            {
                dataGridView1.Rows.Clear();
                numericUpDown5.Value = Convert.ToDecimal(reader.ReadLine());
                for (var line = reader.ReadLine(); line != null; line = reader.ReadLine())
                {
                    var array = line.Split(';').Cast<object>().ToArray();
                    dataGridView1.Rows.Add(array);
                }
            }
            UpdateTotal();
        }

        /// <summary>
        ///     Сохранение файла с параметрами задачи
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void saveFile_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() != DialogResult.OK) return;
            using (var writer = File.CreateText(saveFileDialog1.FileName))
            {
                writer.WriteLine(numericUpDown5.Value);
                for (var index = 0; index < dataGridView1.Rows.Count; index++)
                {
                    writer.WriteLine(dataGridView1[0, index].EditedFormattedValue + ";" +
                                     dataGridView1[1, index].EditedFormattedValue + ";" +
                                     dataGridView1[2, index].EditedFormattedValue + ";" +
                                     dataGridView1[3, index].EditedFormattedValue);
                }
            }
        }

        private void addItem_Click(object sender, EventArgs e)
        {
            object[] array = {numericUpDown1.Value, numericUpDown2.Value, numericUpDown3.Value, numericUpDown4.Value};
            dataGridView1.Rows.Add(array);
            UpdateTotal();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (var i = 0; i < dataGridView1.Rows.Count; i++)
            {
                var v = Convert.ToDouble(dataGridView1[0, i].EditedFormattedValue);
                var k = Convert.ToDouble(dataGridView1[1, i].EditedFormattedValue);
                var q = Convert.ToDouble(dataGridView1[2, i].EditedFormattedValue);
                var c = Convert.ToDouble(dataGridView1[3, i].EditedFormattedValue);
                v = -c + Math.Sqrt(q/k);
                dataGridView1[0, i].Value = Math.Min((decimal) Math.Max(v, 0.0), numericUpDown5.Value);
            }
            UpdateTotal();
        }
    }
}