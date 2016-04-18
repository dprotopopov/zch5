namespace Task01
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.V = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.K = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Q = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.C = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown3 = new System.Windows.Forms.NumericUpDown();
            this.button1 = new System.Windows.Forms.Button();
            this.numericUpDown4 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown5 = new System.Windows.Forms.NumericUpDown();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.numericUpDown6 = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button4 = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown6)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.V,
            this.K,
            this.Q,
            this.C});
            this.dataGridView1.Location = new System.Drawing.Point(71, 64);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 28;
            this.dataGridView1.Size = new System.Drawing.Size(615, 234);
            this.dataGridView1.TabIndex = 0;
            // 
            // V
            // 
            this.V.HeaderText = "v";
            this.V.Name = "V";
            // 
            // K
            // 
            this.K.HeaderText = "k";
            this.K.Name = "K";
            // 
            // Q
            // 
            this.Q.HeaderText = "q";
            this.Q.Name = "Q";
            // 
            // C
            // 
            this.C.HeaderText = "C";
            this.C.Name = "C";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.DecimalPlaces = 2;
            this.numericUpDown1.Location = new System.Drawing.Point(70, 331);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown1.TabIndex = 1;
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.DecimalPlaces = 2;
            this.numericUpDown2.Location = new System.Drawing.Point(196, 331);
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown2.TabIndex = 2;
            // 
            // numericUpDown3
            // 
            this.numericUpDown3.DecimalPlaces = 2;
            this.numericUpDown3.Location = new System.Drawing.Point(322, 331);
            this.numericUpDown3.Name = "numericUpDown3";
            this.numericUpDown3.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown3.TabIndex = 3;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(593, 326);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(91, 34);
            this.button1.TabIndex = 4;
            this.button1.Text = "Add";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.addItem_Click);
            // 
            // numericUpDown4
            // 
            this.numericUpDown4.DecimalPlaces = 2;
            this.numericUpDown4.Location = new System.Drawing.Point(448, 331);
            this.numericUpDown4.Name = "numericUpDown4";
            this.numericUpDown4.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown4.TabIndex = 5;
            // 
            // numericUpDown5
            // 
            this.numericUpDown5.DecimalPlaces = 2;
            this.numericUpDown5.Location = new System.Drawing.Point(533, 32);
            this.numericUpDown5.Name = "numericUpDown5";
            this.numericUpDown5.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown5.TabIndex = 6;
            this.numericUpDown5.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(784, 52);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(106, 36);
            this.button2.TabIndex = 7;
            this.button2.Text = "Загрузить";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.openFile_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(784, 94);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(106, 36);
            this.button3.TabIndex = 8;
            this.button3.Text = "Сохранить";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.saveFile_Click);
            // 
            // numericUpDown6
            // 
            this.numericUpDown6.DecimalPlaces = 2;
            this.numericUpDown6.Location = new System.Drawing.Point(555, 420);
            this.numericUpDown6.Name = "numericUpDown6";
            this.numericUpDown6.ReadOnly = true;
            this.numericUpDown6.Size = new System.Drawing.Size(120, 26);
            this.numericUpDown6.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(67, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(449, 20);
            this.label1.TabIndex = 10;
            this.label1.Text = "верхняя граница частоты запуска процесса сканирования";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(363, 426);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(153, 20);
            this.label2.TabIndex = 11;
            this.label2.Text = "Значение функции";
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(784, 172);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(106, 41);
            this.button4.TabIndex = 12;
            this.button4.Text = "Выполнить";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(913, 549);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDown6);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.numericUpDown5);
            this.Controls.Add(this.numericUpDown4);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.numericUpDown3);
            this.Controls.Add(this.numericUpDown2);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown6)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn V;
        private System.Windows.Forms.DataGridViewTextBoxColumn K;
        private System.Windows.Forms.DataGridViewTextBoxColumn Q;
        private System.Windows.Forms.DataGridViewTextBoxColumn C;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.NumericUpDown numericUpDown3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.NumericUpDown numericUpDown4;
        private System.Windows.Forms.NumericUpDown numericUpDown5;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.NumericUpDown numericUpDown6;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
    }
}

