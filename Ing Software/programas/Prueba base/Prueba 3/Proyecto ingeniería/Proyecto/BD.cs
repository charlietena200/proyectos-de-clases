using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb; // access
using System.Data;
using System.Windows.Forms;

namespace Proyecto
{
    public static class BD
    {
        public static void Insertar(EdoCuenta e)
        {
            string connstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\DatosGenerales2.mdb";
            OleDbConnection c = new OleDbConnection(connstring);

            c.Open(); // Se abre la BD
            Console.WriteLine("Conectado");

            string sqlInsert = "INSERT INTO DatosGenerales2 (folio, fechaEmision, nombre, apPat, apMat, edad, telefono, direccion, fechaRegistro, noCliente, noHabitacion, subTotal, total) VALUES (";
            sqlInsert += e.Folio + ", ";
            sqlInsert += "'" + e.FechaEmision.ToString() + "', ";
            sqlInsert += "'" + e.Nombre + "', ";
            sqlInsert += "'" + e.ApPat + "', ";
            sqlInsert += "'" + e.ApMat + "', ";
            sqlInsert += e.Edad + ", ";
            sqlInsert += "'" + e.Telefono + "', ";
            sqlInsert += "'" + e.Direccion + "', ";
            sqlInsert += "'" + e.FechaRegistro.ToString() + "', ";
            sqlInsert += e.NoCliente + ", ";
            sqlInsert += e.NoHabitacion + ", ";
            sqlInsert += e.SubTotal + ", ";
            sqlInsert += e.Total + ") ";

            //Console.WriteLine(sqlInsert);

            OleDbCommand cmd = new OleDbCommand();
            cmd.Connection = c;
            cmd.CommandText = sqlInsert;

            if (cmd.ExecuteNonQuery() > 0)
            {
                Console.WriteLine("Se ha insertado un nuevo registro");
            }
            else
            {
                Console.WriteLine("Algun problema se presento");
            }
           
            //Console.WriteLine(sqlInsert);

            Consumos x = new Consumos();

            for(int i = 0; i < e.getLen(); i++)
            {
                x=e.getDatosConsumo(x,i);
                sqlInsert = "INSERT INTO Consumos (folio, claveUnica, nombre, claveConsumo, precio, fechaEmision) VALUES (";
                sqlInsert += e.Folio + ", ";
                sqlInsert += x.ClaveUnica + ", ";
                sqlInsert += "'" + x.Nombre + "', ";
                sqlInsert += "'" + x.ClaveConsumo + "', ";
                sqlInsert += x.Precio + ", ";
                sqlInsert += "'" + x.FechaEmision.ToString() + "') ";

                //Console.WriteLine(sqlInsert);
                cmd.CommandText = sqlInsert;

                if (cmd.ExecuteNonQuery() > 0)
                {
                    Console.WriteLine("Se ha insertado un nuevo registro");
                }
                else
                {
                    Console.WriteLine("Algun problema se presento");
                }
            }

            c.Close(); // Se cierra la BD
            Console.WriteLine("Desconectado");
        }
        public static void Buscar(string folioABuscar)
        {
            string connstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\DatosGenerales2.mdb";
            OleDbConnection c = new OleDbConnection(connstring);

            c.Open(); // Se abre la BD
            Console.WriteLine("Conectado");

            string sql = "Select * from DatosGenerales2 WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            OleDbDataAdapter adapter = new OleDbDataAdapter(sql, connstring);

            DataSet d = new DataSet();
            adapter.Fill(d); // llenar el adaptador

            foreach (DataRow row in d.Tables[0].Rows)
            {
                MessageBox.Show($"Folio: {row["folio"]}\nFecha emision: {row["fechaEmision"]}\nNombre: {row["nombre"]}\nApellido Paterno: {row["apPat"]}\nApellido Materno: {row["apMat"]}\nEdad: {row["edad"]}\nTelefono: {row["telefono"]}\nDireccion: {row["direccion"]}\nFecha registro: {row["fechaRegistro"]}\nNumero cliente: {row["noCliente"]}\nNumero habitacion: {row["noHabitacion"]}\nSubtotal: {row["subTotal"]}\nTotal: {row["total"]}");
            }

            sql = "Select * from Consumos WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            adapter = new OleDbDataAdapter(sql, connstring);

            adapter.Fill(d); // llenar el adaptador

            foreach (DataRow row in d.Tables[0].Rows)
            {
                MessageBox.Show($"Folio {row["folio"]}\nClave unica: {row["claveUnica"]}\nNombre: {row["nombre"]}\nClave consumo: {row["claveConsumo"]}\nPrecio: {row["precio"]}\nFecha emision: {row["fechaEmision"]}");
            }

            c.Close(); // Se cierra la BD
            Console.WriteLine("Desconectado");

        }
        public static void Borrar(string folioABuscar)
        {
            string connstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\DatosGenerales2.mdb";
            OleDbConnection c = new OleDbConnection(connstring);

            c.Open(); // Se abre la BD
            Console.WriteLine("Conectado");

            string sql = "DELETE * from DatosGenerales2 WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            OleDbDataAdapter adapter = new OleDbDataAdapter(sql, connstring);

            DataSet d = new DataSet();
            adapter.Fill(d); // llenar el adaptador

            sql = "DELETE * from Consumos WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            adapter = new OleDbDataAdapter(sql, connstring);

            adapter.Fill(d); // llenar el adaptador

            c.Close(); // Se cierra la BD
            Console.WriteLine("Desconectado");
        }
        public static void Actualizar(EdoCuenta e, string folioABuscar)
        {
            string connstring = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=|DataDirectory|\\DatosGenerales.mdb";
            OleDbConnection c = new OleDbConnection(connstring);

            c.Open(); // Se abre la BD
            Console.WriteLine("Conectado");

            string sql = "DELETE * from DatosGenerales2 WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            OleDbDataAdapter adapter = new OleDbDataAdapter(sql, connstring);

            DataSet d = new DataSet();
            adapter.Fill(d); // llenar el adaptador

            string sqlInsert = "INSERT INTO DatosGenerales2 (folio, fechaEmision, nombre, apPat, apMat, edad, telefono, direccion, fechaRegistro, noCliente, noHabitacion, subTotal, total) VALUES (";
            sqlInsert += e.Folio + ", ";
            sqlInsert += "'" + e.FechaEmision.ToString() + "', ";
            sqlInsert += "'" + e.Nombre + "', ";
            sqlInsert += "'" + e.ApPat + "', ";
            sqlInsert += "'" + e.ApMat + "', ";
            sqlInsert += e.Edad + ", ";
            sqlInsert += "'" + e.Telefono + "', ";
            sqlInsert += "'" + e.Direccion + "', ";
            sqlInsert += "'" + e.FechaRegistro.ToString() + "', ";
            sqlInsert += e.NoCliente + ", ";
            sqlInsert += e.NoHabitacion + ", ";
            sqlInsert += e.SubTotal + ", ";
            sqlInsert += e.Total + ") ";

            //Console.WriteLine(sqlInsert);

            OleDbCommand cmd = new OleDbCommand();
            cmd.Connection = c;
            cmd.CommandText = sqlInsert;

            if (cmd.ExecuteNonQuery() > 0)
            {
                Console.WriteLine("Se ha insertado un nuevo registro");
            }
            else
            {
                Console.WriteLine("Algun problema se presento");
            }

            //Console.WriteLine(sqlInsert);

            sql = "DELETE * from Consumos WHERE folio LIKE ";
            sql += folioABuscar;
            //Console.WriteLine(sql);
            adapter = new OleDbDataAdapter(sql, connstring);

            adapter.Fill(d); // llenar el adaptador

            Consumos x = new Consumos();

            for (int i = 0; i < e.getLen(); i++)
            {
                x = e.getDatosConsumo(x, i);
                sqlInsert = "INSERT INTO Consumos (folio, claveUnica, nombre, claveConsumo, precio, fechaEmision) VALUES (";
                sqlInsert += e.Folio + ", ";
                sqlInsert += x.ClaveUnica + ", ";
                sqlInsert += "'" + x.Nombre + "', ";
                sqlInsert += "'" + x.ClaveConsumo + "', ";
                sqlInsert += x.Precio + ", ";
                sqlInsert += "'" + x.FechaEmision.ToString() + "') ";

                //Console.WriteLine(sqlInsert);
                cmd.CommandText = sqlInsert;

                if (cmd.ExecuteNonQuery() > 0)
                {
                    Console.WriteLine("Se ha insertado un nuevo registro");
                }
                else
                {
                    Console.WriteLine("Algun problema se presento");
                }
            }

            c.Close(); // Se cierra la BD
            Console.WriteLine("Desconectado");
        }
    }
}
