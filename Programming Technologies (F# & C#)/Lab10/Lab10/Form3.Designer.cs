namespace Lab10
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxX = new System.Windows.Forms.TextBox();
            this.textBoxY = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxZ = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxResult = new System.Windows.Forms.TextBox();
            this.buttonCalculate = new System.Windows.Forms.Button();
            this.buttonClear = new System.Windows.Forms.Button();
            this.groupBoxF = new System.Windows.Forms.GroupBox();
            this.radioButtonSh = new System.Windows.Forms.RadioButton();
            this.radioButtonX2 = new System.Windows.Forms.RadioButton();
            this.radioButtonEx = new System.Windows.Forms.RadioButton();
            this.groupBoxF.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "X = ";
            // 
            // textBoxX
            // 
            this.textBoxX.Location = new System.Drawing.Point(49, 23);
            this.textBoxX.Name = "textBoxX";
            this.textBoxX.Size = new System.Drawing.Size(100, 20);
            this.textBoxX.TabIndex = 1;
            // 
            // textBoxY
            // 
            this.textBoxY.Location = new System.Drawing.Point(49, 61);
            this.textBoxY.Name = "textBoxY";
            this.textBoxY.Size = new System.Drawing.Size(100, 20);
            this.textBoxY.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Y = ";
            // 
            // textBoxZ
            // 
            this.textBoxZ.Location = new System.Drawing.Point(49, 101);
            this.textBoxZ.Name = "textBoxZ";
            this.textBoxZ.Size = new System.Drawing.Size(100, 20);
            this.textBoxZ.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(27, 104);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Z = ";
            // 
            // textBoxResult
            // 
            this.textBoxResult.Location = new System.Drawing.Point(12, 145);
            this.textBoxResult.Multiline = true;
            this.textBoxResult.Name = "textBoxResult";
            this.textBoxResult.Size = new System.Drawing.Size(305, 109);
            this.textBoxResult.TabIndex = 6;
            // 
            // buttonCalculate
            // 
            this.buttonCalculate.Location = new System.Drawing.Point(62, 275);
            this.buttonCalculate.Name = "buttonCalculate";
            this.buttonCalculate.Size = new System.Drawing.Size(75, 23);
            this.buttonCalculate.TabIndex = 7;
            this.buttonCalculate.Text = "Calculate";
            this.buttonCalculate.UseVisualStyleBackColor = true;
            this.buttonCalculate.Click += new System.EventHandler(this.buttonCalculate_Click);
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(181, 274);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(89, 24);
            this.buttonClear.TabIndex = 8;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // groupBoxF
            // 
            this.groupBoxF.Controls.Add(this.radioButtonEx);
            this.groupBoxF.Controls.Add(this.radioButtonX2);
            this.groupBoxF.Controls.Add(this.radioButtonSh);
            this.groupBoxF.Location = new System.Drawing.Point(181, 21);
            this.groupBoxF.Name = "groupBoxF";
            this.groupBoxF.Size = new System.Drawing.Size(107, 99);
            this.groupBoxF.TabIndex = 9;
            this.groupBoxF.TabStop = false;
            this.groupBoxF.Text = "F(x)";
            // 
            // radioButtonSh
            // 
            this.radioButtonSh.AutoSize = true;
            this.radioButtonSh.Checked = true;
            this.radioButtonSh.Location = new System.Drawing.Point(18, 19);
            this.radioButtonSh.Name = "radioButtonSh";
            this.radioButtonSh.Size = new System.Drawing.Size(47, 17);
            this.radioButtonSh.TabIndex = 0;
            this.radioButtonSh.TabStop = true;
            this.radioButtonSh.Text = "sh(x)";
            this.radioButtonSh.UseVisualStyleBackColor = true;
            // 
            // radioButtonX2
            // 
            this.radioButtonX2.AutoSize = true;
            this.radioButtonX2.Location = new System.Drawing.Point(18, 41);
            this.radioButtonX2.Name = "radioButtonX2";
            this.radioButtonX2.Size = new System.Drawing.Size(42, 17);
            this.radioButtonX2.TabIndex = 1;
            this.radioButtonX2.Text = "x^2";
            this.radioButtonX2.UseVisualStyleBackColor = true;
            // 
            // radioButtonEx
            // 
            this.radioButtonEx.AutoSize = true;
            this.radioButtonEx.Location = new System.Drawing.Point(18, 64);
            this.radioButtonEx.Name = "radioButtonEx";
            this.radioButtonEx.Size = new System.Drawing.Size(42, 17);
            this.radioButtonEx.TabIndex = 2;
            this.radioButtonEx.Text = "e^x";
            this.radioButtonEx.UseVisualStyleBackColor = true;
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(329, 310);
            this.Controls.Add(this.groupBoxF);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.buttonCalculate);
            this.Controls.Add(this.textBoxResult);
            this.Controls.Add(this.textBoxZ);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxY);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBoxX);
            this.Controls.Add(this.label1);
            this.Name = "Form3";
            this.Text = "Form3";
            this.groupBoxF.ResumeLayout(false);
            this.groupBoxF.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxX;
        private System.Windows.Forms.TextBox textBoxY;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxZ;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxResult;
        private System.Windows.Forms.Button buttonCalculate;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.GroupBox groupBoxF;
        private System.Windows.Forms.RadioButton radioButtonEx;
        private System.Windows.Forms.RadioButton radioButtonX2;
        private System.Windows.Forms.RadioButton radioButtonSh;
    }
}